import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Twist
from turtlesim.srv import SetPen

import threading


class MinimalPublisher(Node):

    def __init__(self):
        super().__init__('turtle_shape')

     
        # cmd_vel Publisher
        ## hw2에서 썼던 구조와 동일

        self.publisher_ = self.create_publisher(
            Twist,
            '/turtle1/cmd_vel',
            10
        )

   
        # SetPen Service Client
        # SetPen Services는 turtlesim 노드에서 제공하는 서비스 통신으로, 펜의 색상과 두께를 설정할 수 있음
        self.pen_client = self.create_client(
            SetPen,
            '/turtle1/set_pen'
        )

   
        # 현재 선택된 도형
   
        self.shape = None

    
        # 그리기 상태
  
        self.state = 0

        self.start_time = self.get_clock().now()

    
        # 입력 상태
  
        self.drawing = False

     
        # 기본 펜 설정
  
        self.pen_r = 255
        self.pen_g = 255
        self.pen_b = 255
        self.pen_width = 2

        # 0.01초마다 실행
  
        self.timer = self.create_timer(
            0.01,
            self.timer_callback
        )

       
        # 키보드 입력 Thread
      
        self.input_thread = threading.Thread(
            target=self.keyboard_input,
            daemon=True
        )

        self.input_thread.start()

   
    # 키보드 입력
 
    def keyboard_input(self):

        while rclpy.ok():

            print()
            print("==============================")
            print("도형을 선택하세요.")
            print("W : 사각형")
            print("S : 삼각형")
            print("A : 원")
            print("D : 종료")
            print("==============================")

            key = input("입력 : ").strip().upper()

            # 종료
            if key == 'D':

                print("프로그램을 종료합니다.")

                rclpy.shutdown()

                break

            # 사각형
            elif key == 'W':

                self.shape = 'square'

                self.pen_r = 0
                self.pen_g = 255
                self.pen_b = 0
                self.pen_width = 5

                print("사각형 선택")

            # 삼각형
            elif key == 'S':

                self.shape = 'triangle'

                self.pen_r = 255
                self.pen_g = 0
                self.pen_b = 0
                self.pen_width = 3

                print("삼각형 선택")

            elif key == 'A':

                self.shape = 'circle'

                self.pen_r = 0
                self.pen_g = 0
                self.pen_b = 255
                self.pen_width = 7

                print("원 선택")
            
            # 잘못된 입력
            else:

                print("잘못된 입력입니다.")

                continue

            # 펜 설정
            self.set_pen()

            # 도형 그리기 시작
            self.state = 0
            self.start_time = self.get_clock().now()
            self.drawing = True

            

        # 펜 설정

    def set_pen(self):

        if not self.pen_client.wait_for_service(timeout_sec=1.0):

            self.get_logger().warning(
                '/turtle1/set_pen 서비스를 찾을 수 없습니다.'
            )

            return

        request = SetPen.Request()

        request.r = self.pen_r
        request.g = self.pen_g
        request.b = self.pen_b
        request.width = self.pen_width
        request.off = 0

        self.pen_client.call_async(request)

    # 시간 계산
 
    def elapsed_time(self):

        return (
            self.get_clock().now()
            - self.start_time
        ).nanoseconds / 1e9

   
    # 메인 그리기 Callback
   
    # hw1 에서 작성한 각도와 속도 참고하여 사용
    
    def timer_callback(self):

        msg = Twist()

        # 그리는 중이 아니면 정지

        if not self.drawing:

            msg.linear.x = 0.0
            msg.angular.z = 0.0

            self.publisher_.publish(msg)

            return

        elapsed = self.elapsed_time()

       
        # 삼각형
 
        if self.shape == 'triangle':

            # 1번째 변

            if self.state == 0:

                msg.linear.x = 2.0
                msg.angular.z = 0.0

                if elapsed >= 1.5:

                    self.state = 1
                    self.start_time = self.get_clock().now()

            # 1번째 120도 회전

            elif self.state == 1:

                msg.linear.x = 0.0
                msg.angular.z = 2.0

                if elapsed >= 1.047:

                    self.state = 2
                    self.start_time = self.get_clock().now()

            # 2번째 변

            elif self.state == 2:

                msg.linear.x = 2.0
                msg.angular.z = 0.0

                if elapsed >= 1.5:

                    self.state = 3
                    self.start_time = self.get_clock().now()

            # 2번째 120도 회전

            elif self.state == 3:

                msg.linear.x = 0.0
                msg.angular.z = 2.0

                if elapsed >= 1.047:

                    self.state = 4
                    self.start_time = self.get_clock().now()

            # 3번째 변

            elif self.state == 4:

                msg.linear.x = 2.0
                msg.angular.z = 0.0

                if elapsed >= 1.5:

                    self.state = 5
                    self.start_time = self.get_clock().now()

            # 3번째 120도 회전

            elif self.state == 5:

                msg.linear.x = 0.0
                msg.angular.z = 2.0

                if elapsed >= 1.047:

                    self.state = 6
                    self.start_time = self.get_clock().now()

            # 정지

            elif self.state == 6:

                msg.linear.x = 0.0
                msg.angular.z = 0.0

                self.drawing = False

                print()
                print("삼각형 그리기 완료.")
 
        # 사각형
       

        elif self.shape == 'square':

            # 1번째 변

            if self.state == 0:

                msg.linear.x = 2.0
                msg.angular.z = 0.0

                if elapsed >= 1.5:

                    self.state = 1
                    self.start_time = self.get_clock().now()

            # 1번째 90도 회전

            elif self.state == 1:

                msg.linear.x = 0.0
                msg.angular.z = 2.0

                if elapsed >= 0.785:

                    self.state = 2
                    self.start_time = self.get_clock().now()

            # 2번째 변

            elif self.state == 2:

                msg.linear.x = 2.0
                msg.angular.z = 0.0

                if elapsed >= 1.5:

                    self.state = 3
                    self.start_time = self.get_clock().now()

            # 2번째 90도 회전

            elif self.state == 3:

                msg.linear.x = 0.0
                msg.angular.z = 2.0

                if elapsed >= 0.785:

                    self.state = 4
                    self.start_time = self.get_clock().now()

            # 3번째 변

            elif self.state == 4:

                msg.linear.x = 2.0
                msg.angular.z = 0.0

                if elapsed >= 1.5:

                    self.state = 5
                    self.start_time = self.get_clock().now()

            # 3번째 90도 회전

            elif self.state == 5:

                msg.linear.x = 0.0
                msg.angular.z = 2.0

                if elapsed >= 0.785:

                    self.state = 6
                    self.start_time = self.get_clock().now()

            # 4번째 변

            elif self.state == 6:

                msg.linear.x = 2.0
                msg.angular.z = 0.0

                if elapsed >= 1.5:

                    self.state = 7
                    self.start_time = self.get_clock().now()

            # 4번째 90도 회전

            elif self.state == 7:

                msg.linear.x = 0.0
                msg.angular.z = 2.0

                if elapsed >= 0.785:

                    self.state = 8
                    self.start_time = self.get_clock().now()

            # 정지

            elif self.state == 8:

                msg.linear.x = 0.0
                msg.angular.z = 0.0

                self.drawing = False

                print()
                print("사각형 그리기 완료.")

        elif self.shape == 'circle':

            msg.linear.x = 2.0
            msg.angular.z = 1.0

            if elapsed >= 6.283:

                msg.linear.x = 0.0
                msg.angular.z = 0.0

                self.drawing = False

                print()
                print("원 그리기 완료.")


        self.publisher_.publish(msg)


def main(args=None):

    rclpy.init(args=args)

    node = MinimalPublisher()

    try:

        rclpy.spin(node)

    except KeyboardInterrupt:

        pass

    finally:

        node.destroy_node()

        if rclpy.ok():

            rclpy.shutdown()


if __name__ == '__main__':

    main()