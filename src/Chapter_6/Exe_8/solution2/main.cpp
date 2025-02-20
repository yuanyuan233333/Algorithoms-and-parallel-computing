#include <iostream>
#include <vector>

#include "DataFrame.h"

int main()
{
  std::cout << "Test DataFrame" << std::endl;
  DataFrame df ("c1 c2");
  df.print();
  std::cout << std::endl;

  std::vector<double> v1 = {1, 2, 3};
  std::vector<double> v2 = {4, 5, 6};
  df.set_column ("c1", v1);
  df.set_column ("c2", v2);
  df.set_column ("c2", v1);
  df.set_column ("c3", v1);
  df.print();
  std::cout << std::endl;

  std::vector<double> v_res = df.get_column ("c1");
  std::cout << "Printing v_res" << std::endl;
  for (size_t i = 0; i < v_res.size(); i++)
    std::cout << v_res[i] << " ";
  std::cout << "\n" << std::endl;

  v_res = df.get_column ("c3");
  std::cout << "Printing v_res" << std::endl;
  for (size_t i = 0; i < v_res.size(); i++)
    std::cout << v_res[i] << " ";
  std::cout << std::endl;

  std::cout << "mean of c1 = " << df.get_mean ("c1") << std::endl;
  std::cout << "mean of c2 = " << df.get_mean ("c2") << std::endl;

  df.set_column ("c2", v2);

  std::vector<double> v3 = {4, 5};
  df.set_column ("c2", v3);

  std::cout << "mean of c2 = " << df.get_mean ("c2") << std::endl;
  std::cout << "mean of c3 = " << df.get_mean ("c3") << std::endl;
  std::cout << "(c2,1) = " << df.get_element_at ("c2", 1) << std::endl;
  std::cout << "(c2,4) = " << df.get_element_at ("c2", 4) << std::endl;
  std::cout << "(c3,1) = " << df.get_element_at ("c3", 1) << std::endl;
  
  df.set_element_at ("c2", 1, 27);
  std::cout << "(c2,1) = " << df.get_element_at ("c2", 1) << std::endl;
  
  df.add_column ("c3", v1);
  std::cout << "\ndf after add" << std::endl;
  df.print();
  std::cout << std::endl;
  
  DataFrame select_df = df.select_equal("c2", 27);
  std::cout << "select_df " <<  std::endl;
  select_df.print();

  return 0;
}
