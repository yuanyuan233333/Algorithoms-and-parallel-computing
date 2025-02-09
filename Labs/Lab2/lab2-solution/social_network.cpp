///Header include
#include "social_network.hpp"
#include "user.hpp"

///STD include
#include <iostream>

namespace SocialNetworkNS {
size_t SocialNetwork::CUserIndex(const std::string &name,
                                 const std::string &surname) const {
  size_t i;

  User u(name, surname);

  bool found = false;

  for (i = 0; i < users.size() && !found; ++i)
    if (users[i] == u)
      found = true;

  if (found)
    return --i;
  else
    return users.size();
}

void SocialNetwork::AddUser(const std::string &name,
                            const std::string &surname) {

  size_t user_index = CUserIndex(name, surname);

  if (user_index != users.size())
    return;

  User user(name, surname);
  users.push_back(user);
  friends.push_back({});

}

const std::vector <User> SocialNetwork::CGetUsers() const {
  return users;
}

const std::vector <User> SocialNetwork::CGetFriends(const User &user) const {
    std::vector <User> c_get_friends;
    c_get_friends = CGetFriends(user.CGetName(), user.CGetSurname());
    return c_get_friends;
}

const std::vector <User> SocialNetwork::CGetFriends(const std::string &name,
                                                    const std::string &surname) const {
  std::vector <User> ret{};

  // user index
  size_t i = CUserIndex(name, surname);
  if (i < users.size()) {
    for (size_t j: friends[i])
      ret.push_back(users[j]);
  }

  return ret;
}

void SocialNetwork::AddFriendship(const std::string &first_name,
                                  const std::string &first_surname,
                                  const std::string &second_name,
                                  const std::string &second_surname) {

  const User first_user = User(first_name, first_surname);
  const User second_user = User(second_name, second_surname);

  // check if the two users exist

  size_t first_user_index = CUserIndex(first_name, first_surname);
  size_t second_user_index = CUserIndex(second_name, second_surname);

  if (first_user_index == users.size() || second_user_index == users.size())
    return; // do nothing: one user at least does not exist

  if (first_user == second_user)
    return; // do nothing: one user cannot be friend of her/himself

  // check if friendship already exists, in this case do nothing
  bool friend_found = false;
  for (size_t i = 0; i < friends[first_user_index].size() && !friend_found; ++i)
    if (friends[first_user_index][i] == second_user_index)
      friend_found = true;

  if (!friend_found) // add mutual friendship
  {
    friends[first_user_index].push_back(second_user_index);
    friends[second_user_index].push_back(first_user_index);
  }
}

}
