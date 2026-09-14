#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "qt_project__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__qt_project__msg__SeatStatus() -> *const std::ffi::c_void;
}

#[link(name = "qt_project__rosidl_generator_c")]
extern "C" {
    fn qt_project__msg__SeatStatus__init(msg: *mut SeatStatus) -> bool;
    fn qt_project__msg__SeatStatus__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SeatStatus>, size: usize) -> bool;
    fn qt_project__msg__SeatStatus__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SeatStatus>);
    fn qt_project__msg__SeatStatus__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SeatStatus>, out_seq: *mut rosidl_runtime_rs::Sequence<SeatStatus>) -> bool;
}

// Corresponds to qt_project__msg__SeatStatus
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SeatStatus {

    // This member is not documented.
    #[allow(missing_docs)]
    pub seat_id: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub occupied: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub has_belongings: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub absence_start_time: i64,

}



impl Default for SeatStatus {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !qt_project__msg__SeatStatus__init(&mut msg as *mut _) {
        panic!("Call to qt_project__msg__SeatStatus__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SeatStatus {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { qt_project__msg__SeatStatus__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { qt_project__msg__SeatStatus__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { qt_project__msg__SeatStatus__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SeatStatus {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SeatStatus where Self: Sized {
  const TYPE_NAME: &'static str = "qt_project/msg/SeatStatus";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__qt_project__msg__SeatStatus() }
  }
}


#[link(name = "qt_project__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__qt_project__msg__SeatCommand() -> *const std::ffi::c_void;
}

#[link(name = "qt_project__rosidl_generator_c")]
extern "C" {
    fn qt_project__msg__SeatCommand__init(msg: *mut SeatCommand) -> bool;
    fn qt_project__msg__SeatCommand__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SeatCommand>, size: usize) -> bool;
    fn qt_project__msg__SeatCommand__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SeatCommand>);
    fn qt_project__msg__SeatCommand__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SeatCommand>, out_seq: *mut rosidl_runtime_rs::Sequence<SeatCommand>) -> bool;
}

// Corresponds to qt_project__msg__SeatCommand
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SeatCommand {

    // This member is not documented.
    #[allow(missing_docs)]
    pub seat_id: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub occupied: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub has_belongings: bool,

}



impl Default for SeatCommand {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !qt_project__msg__SeatCommand__init(&mut msg as *mut _) {
        panic!("Call to qt_project__msg__SeatCommand__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SeatCommand {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { qt_project__msg__SeatCommand__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { qt_project__msg__SeatCommand__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { qt_project__msg__SeatCommand__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SeatCommand {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SeatCommand where Self: Sized {
  const TYPE_NAME: &'static str = "qt_project/msg/SeatCommand";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__qt_project__msg__SeatCommand() }
  }
}


