#ifndef INCOMINGMSG_H
#define INCOMINGMSG_H

#include <string>
#include <ctime>


//! IncomingMsg  unmarshalls the JSON msg from the groupme server
class IncomingMsg{
 public:
  //! Default constructor - mosty unused
  IncomingMsg();

  //! Constructor used for Unmarshalling JSON from HTTP Request
  IncomingMsg(std::string);
  ~IncomingMsg();

  //! Time message was created
  std::time Time();

  //! GroupID that message was posted
  std::string GroupID();

  //! Unique ID of the message
  std::string ID();

  //! Name of the poster
  std::string Name();

  //! String Numeric ID of poster
  std::string SenderID();

  //! Type of Poster  (i.e. user/bot)
  std::string SenderType();

  //! Message Body
  std::string Text();

 private:

  struct IncMsg _msg;
}
#endif
