#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "qt_project__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__qt_project__srv__GetRoute_Request() -> *const std::ffi::c_void;
}

#[link(name = "qt_project__rosidl_generator_c")]
extern "C" {
    fn qt_project__srv__GetRoute_Request__init(msg: *mut GetRoute_Request) -> bool;
    fn qt_project__srv__GetRoute_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetRoute_Request>, size: usize) -> bool;
    fn qt_project__srv__GetRoute_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetRoute_Request>);
    fn qt_project__srv__GetRoute_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetRoute_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GetRoute_Request>) -> bool;
}

// Corresponds to qt_project__srv__GetRoute_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetRoute_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub seat_ids: rosidl_runtime_rs::Sequence<i32>,

}



impl Default for GetRoute_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !qt_project__srv__GetRoute_Request__init(&mut msg as *mut _) {
        panic!("Call to qt_project__srv__GetRoute_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetRoute_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { qt_project__srv__GetRoute_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { qt_project__srv__GetRoute_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { qt_project__srv__GetRoute_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetRoute_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetRoute_Request where Self: Sized {
  const TYPE_NAME: &'static str = "qt_project/srv/GetRoute_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__qt_project__srv__GetRoute_Request() }
  }
}


#[link(name = "qt_project__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__qt_project__srv__GetRoute_Response() -> *const std::ffi::c_void;
}

#[link(name = "qt_project__rosidl_generator_c")]
extern "C" {
    fn qt_project__srv__GetRoute_Response__init(msg: *mut GetRoute_Response) -> bool;
    fn qt_project__srv__GetRoute_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetRoute_Response>, size: usize) -> bool;
    fn qt_project__srv__GetRoute_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetRoute_Response>);
    fn qt_project__srv__GetRoute_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetRoute_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GetRoute_Response>) -> bool;
}

// Corresponds to qt_project__srv__GetRoute_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetRoute_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub route: rosidl_runtime_rs::Sequence<i32>,

}



impl Default for GetRoute_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !qt_project__srv__GetRoute_Response__init(&mut msg as *mut _) {
        panic!("Call to qt_project__srv__GetRoute_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetRoute_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { qt_project__srv__GetRoute_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { qt_project__srv__GetRoute_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { qt_project__srv__GetRoute_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetRoute_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetRoute_Response where Self: Sized {
  const TYPE_NAME: &'static str = "qt_project/srv/GetRoute_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__qt_project__srv__GetRoute_Response() }
  }
}


#[link(name = "qt_project__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__qt_project__srv__ProcessPenalty_Request() -> *const std::ffi::c_void;
}

#[link(name = "qt_project__rosidl_generator_c")]
extern "C" {
    fn qt_project__srv__ProcessPenalty_Request__init(msg: *mut ProcessPenalty_Request) -> bool;
    fn qt_project__srv__ProcessPenalty_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ProcessPenalty_Request>, size: usize) -> bool;
    fn qt_project__srv__ProcessPenalty_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ProcessPenalty_Request>);
    fn qt_project__srv__ProcessPenalty_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ProcessPenalty_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ProcessPenalty_Request>) -> bool;
}

// Corresponds to qt_project__srv__ProcessPenalty_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ProcessPenalty_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub seat_ids: rosidl_runtime_rs::Sequence<i32>,

}



impl Default for ProcessPenalty_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !qt_project__srv__ProcessPenalty_Request__init(&mut msg as *mut _) {
        panic!("Call to qt_project__srv__ProcessPenalty_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ProcessPenalty_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { qt_project__srv__ProcessPenalty_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { qt_project__srv__ProcessPenalty_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { qt_project__srv__ProcessPenalty_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ProcessPenalty_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ProcessPenalty_Request where Self: Sized {
  const TYPE_NAME: &'static str = "qt_project/srv/ProcessPenalty_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__qt_project__srv__ProcessPenalty_Request() }
  }
}


#[link(name = "qt_project__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__qt_project__srv__ProcessPenalty_Response() -> *const std::ffi::c_void;
}

#[link(name = "qt_project__rosidl_generator_c")]
extern "C" {
    fn qt_project__srv__ProcessPenalty_Response__init(msg: *mut ProcessPenalty_Response) -> bool;
    fn qt_project__srv__ProcessPenalty_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ProcessPenalty_Response>, size: usize) -> bool;
    fn qt_project__srv__ProcessPenalty_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ProcessPenalty_Response>);
    fn qt_project__srv__ProcessPenalty_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ProcessPenalty_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ProcessPenalty_Response>) -> bool;
}

// Corresponds to qt_project__srv__ProcessPenalty_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ProcessPenalty_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for ProcessPenalty_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !qt_project__srv__ProcessPenalty_Response__init(&mut msg as *mut _) {
        panic!("Call to qt_project__srv__ProcessPenalty_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ProcessPenalty_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { qt_project__srv__ProcessPenalty_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { qt_project__srv__ProcessPenalty_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { qt_project__srv__ProcessPenalty_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ProcessPenalty_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ProcessPenalty_Response where Self: Sized {
  const TYPE_NAME: &'static str = "qt_project/srv/ProcessPenalty_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__qt_project__srv__ProcessPenalty_Response() }
  }
}






#[link(name = "qt_project__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__qt_project__srv__GetRoute() -> *const std::ffi::c_void;
}

// Corresponds to qt_project__srv__GetRoute
#[allow(missing_docs, non_camel_case_types)]
pub struct GetRoute;

impl rosidl_runtime_rs::Service for GetRoute {
    type Request = GetRoute_Request;
    type Response = GetRoute_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__qt_project__srv__GetRoute() }
    }
}




#[link(name = "qt_project__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__qt_project__srv__ProcessPenalty() -> *const std::ffi::c_void;
}

// Corresponds to qt_project__srv__ProcessPenalty
#[allow(missing_docs, non_camel_case_types)]
pub struct ProcessPenalty;

impl rosidl_runtime_rs::Service for ProcessPenalty {
    type Request = ProcessPenalty_Request;
    type Response = ProcessPenalty_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__qt_project__srv__ProcessPenalty() }
    }
}


