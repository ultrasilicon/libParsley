#ifndef PCHECK_H
#define PCHECK_H

#include "Parsley.h"

PARSLEY_NAMESPACE_BEGIN
class CheckUtils;
class Check;

class CheckUtils
    : public PObject<uv_check_t, Check>
{
public:
  CheckUtils(Loop *l) : PObject(l){}

protected:
  static void checkCb(uv_check_t *r);

};

class Check
    : CheckUtils
{
public:
  Check(Loop *l);
  ~Check();

  Callback<void> onCalled;

  int start();
  int stop();
};



PARSLEY_NAMESPACE_END
#endif // PCHECK_H