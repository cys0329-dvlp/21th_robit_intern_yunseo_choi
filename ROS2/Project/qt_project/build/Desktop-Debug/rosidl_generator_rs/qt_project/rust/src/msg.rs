#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to qt_project__msg__SeatStatus

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::SeatStatus::default())
  }
}

impl rosidl_runtime_rs::Message for SeatStatus {
  type RmwMsg = super::msg::rmw::SeatStatus;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        seat_id: msg.seat_id,
        occupied: msg.occupied,
        has_belongings: msg.has_belongings,
        absence_start_time: msg.absence_start_time,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      seat_id: msg.seat_id,
      occupied: msg.occupied,
      has_belongings: msg.has_belongings,
      absence_start_time: msg.absence_start_time,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      seat_id: msg.seat_id,
      occupied: msg.occupied,
      has_belongings: msg.has_belongings,
      absence_start_time: msg.absence_start_time,
    }
  }
}


// Corresponds to qt_project__msg__SeatCommand

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::SeatCommand::default())
  }
}

impl rosidl_runtime_rs::Message for SeatCommand {
  type RmwMsg = super::msg::rmw::SeatCommand;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        seat_id: msg.seat_id,
        occupied: msg.occupied,
        has_belongings: msg.has_belongings,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      seat_id: msg.seat_id,
      occupied: msg.occupied,
      has_belongings: msg.has_belongings,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      seat_id: msg.seat_id,
      occupied: msg.occupied,
      has_belongings: msg.has_belongings,
    }
  }
}


