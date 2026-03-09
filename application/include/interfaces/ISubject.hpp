#ifndef I_SUBJECT_HPP
#define I_SUBJECT_HPP

#include "interfaces/IObserver.hpp"

// Source: https://refactoring.guru/design-patterns/observer/cpp/example

class ISubject {
 public:
  virtual ~ISubject(){};
  virtual void Attach(std::weak_ptr<IObserver> observer) = 0;
  virtual void Detach(std::weak_ptr<IObserver> observer) = 0;
  virtual void Notify() = 0;
};

#endif