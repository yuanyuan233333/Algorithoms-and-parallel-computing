///Header include
#include "social_network.hpp"
#include "user.hpp"

///STD include
#include <iostream>

namespace SocialNetworkNS
{
    //O(N)
  size_t SocialNetwork::CUserIndex(const std::string & name, 
                                   const std::string & surname) const
  {
      size_t i;

      User u(name, surname); //O(1)

      bool found =false; //O(1)
        // O(N)
      for (i  = 0; i <users.size() && !found; ++i)
          if (users[i] == u)//O(1)
              found = true;

          //O(1)
      if (found)
          return --i;
      else
          return users.size();
  }

    //O(N)
  void SocialNetwork::AddUser(const std::string & name, 
                              const std::string & surname)
  {

      size_t user_index = CUserIndex(name, surname);//O(N)

      if (user_index != users.size())//O(1)
          return;

      User user(name, surname);//O(1)
      users.push_back(user);//O(N)
      friends.push_back({});//O(N)

  }

    //O(N)
  const std::vector<User>   SocialNetwork::CGetUsers() const
  {
      return users;
  }

    //O(N^2)
  const std::vector<User> SocialNetwork::CGetFriends(const User & user) const
  {
      return CGetFriends(user.CGetName(),user.CGetSurname());//O(N^2+N)
  }


    //O(N^2)

  const std::vector<User> SocialNetwork::CGetFriends(const std::string & name, 
                                            const std::string  & surname) const
  {
      std::vector<User> ret{};

      // user index
      size_t i = CUserIndex(name,surname);//O(N)
        //O(N^2)
      if (i < users.size())//O(1)
      { //O(N^2)
          for (size_t j : friends[i])//how many iterations? N
              ret.push_back(users[j]);// O(i)
      }

      return ret; //O(N)
  }

  /* v: vector
   *
   * Bubble sort!
   * for (size_t i =0; i<v.size()++i)  N
   *    for size_t j =0 ; j<i-1 ; ++j) 1, 2, 3, ....N-1
   *        if(v[j]>v[i])
   *            swap(v[i],v[j])
   *
   * */

    //O(N)
  void SocialNetwork::AddFriendship(const std::string & first_name,
                                    const std::string & first_surname,
                                    const std::string & second_name,
                                    const std::string & second_surname)
  {

      //O(1)
      const User first_user = User(first_name, first_surname);
      const User second_user = User(second_name, second_surname);

      // check if the two users exist

      //O(N)
      size_t first_user_index = CUserIndex(first_name,first_surname);
      size_t second_user_index = CUserIndex(second_name,second_surname);

      //O(1)
      if (first_user_index == users.size() || second_user_index == users.size())
          return; // do nothing: one user at least does not exist

      if (first_user_index == second_user_index)
          return; // do nothing: one user cannot be friend of her/himself

      // check if friendship already exists, in this case do nothing
      bool friend_found = false;

      //O(N)
      for (size_t i = 0; i<friends[first_user_index].size() && !friend_found; ++i)
          if (friends[first_user_index][i] == second_user_index)
              friend_found = true;

          //O(N)
      if (!friend_found) // add mutual friendship
      {
          //O(N)
          friends[first_user_index].push_back(second_user_index);
          friends[second_user_index].push_back(first_user_index);
      }
  }

}
