//
// Created by noam on 24/01/2020.
//

#ifndef EX4__STATE_H_
#define EX4__STATE_H_

#include <list>
#include <string>

using namespace std;

template <class T>
class State {
 public:
  // Input: s - The state
  // Constructs a state.
  explicit State(T s): state(s), previous_state(nullptr), cost(0), heuristic_cost(0) {}

  // Input: s - The state
  //        c - Its cost.
  // Constructs a state with that cost.
  State(T s, double c): state(s), previous_state(nullptr), cost(c), heuristic_cost(0) {}

  // Input: s - A state
  // Output: True or false whether this state is equal to the other state.
  bool operator==(const State<T> &s) const;

  // Returns this state.
  T GetState() const {
    return this->state;
  }

  // Returns this state's cost - the cost of the path leads to this state.
  double GetCost() const {
    return this->cost;
  }

  // Returns this state's heuristic cost - the cost of the path leads to this state.
  double GetHeuristicCost() const {
    return this->heuristic_cost;
  }

  // Input: s - The state before this state in the path leads to this state.
  //        local_cost - The cost of the last action in the path leads to this state.
  // Sets that state as this state's previous state and that path's cost.
  void SetPreviousState(State<T> *s, double local_cost) {
    this->previous_state = s;
    this->cost = s->cost + local_cost;
  }

  // Input: hc - The heuristic cost to set for this state.
  // Sets the heuristic cost of this state.
  void SetHeuristicCost(double hc) {
    this->heuristic_cost = hc;
  }

  // Output: The path leads to this state.
  // Backtraces that path and returns it.
  list<State<T>*> BacktracePath();

 private:
  T state;
  double cost;
  double heuristic_cost;
  State<T> *previous_state;
};

template<class T>
bool State<T>::operator==(const State<T> &s) const {
  return this->state == s.state;
}

template<class T>
list<State<T>*> State<T>::BacktracePath() {
  list<State<T>*> path;

  if (this->previous_state != nullptr) {
    // Backtraces the path until the previous state.
    path = this->previous_state->BacktracePath();
  }

  // Adds this state to the path.
  path.push_back(this);
  return path;
}

#endif //EX4__STATE_H_
