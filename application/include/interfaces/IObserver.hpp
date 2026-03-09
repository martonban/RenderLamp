#ifndef I_OBSERVER_HPP
#define I_OBSERVER_HPP

#include <string>
#include "server/ServerRequest.hpp"

// Source: https://refactoring.guru/design-patterns/observer/cpp/example 

class IObserver {
 public:
  virtual ~IObserver(){};
  virtual void Update(const ServerRequest& request) = 0;
};

#endif