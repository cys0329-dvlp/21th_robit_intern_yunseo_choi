#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to qt_project__srv__GetRoute_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetRoute_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub seat_ids: Vec<i32>,

}



impl Default for GetRoute_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetRoute_Request::default())
  }
}

impl rosidl_runtime_rs::Message for GetRoute_Request {
  type RmwMsg = super::srv::rmw::GetRoute_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        seat_ids: msg.seat_ids.into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        seat_ids: msg.seat_ids.as_slice().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      seat_ids: msg.seat_ids
          .into_iter()
          .collect(),
    }
  }
}


// Corresponds to qt_project__srv__GetRoute_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetRoute_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub route: Vec<i32>,

}



impl Default for GetRoute_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetRoute_Response::default())
  }
}

impl rosidl_runtime_rs::Message for GetRoute_Response {
  type RmwMsg = super::srv::rmw::GetRoute_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        route: msg.route.into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        route: msg.route.as_slice().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      route: msg.route
          .into_iter()
          .collect(),
    }
  }
}


// Corresponds to qt_project__srv__ProcessPenalty_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ProcessPenalty_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub seat_ids: Vec<i32>,

}



impl Default for ProcessPenalty_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::ProcessPenalty_Request::default())
  }
}

impl rosidl_runtime_rs::Message for ProcessPenalty_Request {
  type RmwMsg = super::srv::rmw::ProcessPenalty_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        seat_ids: msg.seat_ids.into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        seat_ids: msg.seat_ids.as_slice().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      seat_ids: msg.seat_ids
          .into_iter()
          .collect(),
    }
  }
}


// Corresponds to qt_project__srv__ProcessPenalty_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ProcessPenalty_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for ProcessPenalty_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::ProcessPenalty_Response::default())
  }
}

impl rosidl_runtime_rs::Message for ProcessPenalty_Response {
  type RmwMsg = super::srv::rmw::ProcessPenalty_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
    }
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


