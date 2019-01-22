#ifndef PADDRESS_H
#define PADDRESS_H

#include "Parsley.h"

#include <netinet/in.h>

P_NS_BEGIN
class IPAddress;

class IPAddress
{
public:
  enum Version {
    None = 0,
    IPv4 = 1,
    IPv6 = 2,
  };

  IPAddress();
  IPAddress(sockaddr_storage *addr);
  IPAddress(sockaddr_in *addr);
  IPAddress(sockaddr_in6 *addr);
  IPAddress(const std::string& addr, const uint16_t& port);
  ~IPAddress();

  static std::string toString(sockaddr_storage &addr);
  static char* toIPString(const sockaddr_in &addr);
  static char* toIPString(const sockaddr_in6 &addr);

  void setAddress(sockaddr_in *addr);
  void setAddress(sockaddr_in6 *addr);
  void setAddress(const std::string& addr, const uint16_t& port);
  Version version() const;
  std::string toIPString() const;

private:
  Version m_version = None;
  sockaddr_in *m_ip4 = nullptr;
  sockaddr_in6 *m_ip6 = nullptr;
};



P_NS_END
#endif // PADDRESS_H
