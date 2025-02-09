#include "counter_queue.h"

namespace supermarket {
bool counter_queue::pick_number(const std::string &customer_id) {
  const std::pair<std::unordered_set<std::string>::iterator,
                  bool> outcome = m_in_line.insert(customer_id);
  bool added_in_queue = outcome.second;
  if (added_in_queue) {
    m_order.push(customer_id);
  }
  return added_in_queue;
}

std::string counter_queue::next_customer() {
  const std::string next = m_order.front();
  m_order.pop();
  m_in_line.erase(next);
  return next;
}

bool counter_queue::empty() const {
  return m_order.empty();
}
}
