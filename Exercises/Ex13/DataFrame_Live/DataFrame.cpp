#include "DataFrame.h"

DataFrame::DataFrame (void)
  : added_first_column (false), n_rows (0) 
{}



std::vector<DataFrame::key_type>
DataFrame::split (const key_type & s,  char delim) const
{
  key_type word;
  std::vector<key_type> v;
  std::istringstream columns (s);

  while (std::getline (columns, word, delim)) v.push_back (word);

  return v;
}



void
DataFrame::print (void) const
{
  for (const value_type & element : df_data)
    {
      std::cout << element.first << " :: ";

      for (const double & d : element.second)
        std::cout << d << " ";

      std::cout << std::endl;
    }
}



// Question 1
DataFrame::DataFrame (const key_type & c_names)
  : DataFrame ()
{
  auto column_names = split(c_names, ' ');
  for (const auto & column_name : column_names)
    df_data[column_name];

}



// UTILITY for next questions
bool
DataFrame::check_column_name (const key_type & column_name) const
{
    return df_data.find (column_name) != df_data.end();
}



// UTILITY for next questions
void
DataFrame::set_column_data (const key_type & column_name,
                            const mapped_type & column_data)
{
    if(!added_first_column){// new column added, change n_rows
      added_first_column = true;
      n_rows = column_data.size ();
      for (auto it = df_data.begin (); it != df_data.end (); ++it){
		it->second.resize (n_rows);
      }
      df_data[column_name] = column_data;

    }
    else{// at least one column exists check n_rows
      	if(column_data.size () == n_rows){//OK!
			df_data[column_name] = column_data;
      	}
        else{//Error!
          std::cerr << "Error, " << column_name
                    << " has a different number of rows"
                    << std::endl;

        }
    }
}



// Question 2
void
DataFrame::set_column (const key_type & column_name,
                        const mapped_type & column_data)
{
    if(check_column_name (column_name))
      set_column_data (column_name, column_data);
    else
      std::cerr << "Error, " << column_name << " is unknown" << std::endl;
}



// Question 3
void
DataFrame::set_element_at (const key_type & column_name,
                            size_type index, double value)
{
    if(check_column_name (column_name))
      if(index < n_rows){
        df_data[column_name][index] = value;
        }
    	else {//Out range!!!
      	std::cerr << "Error, index out of bound" << std::endl;
        }
    else //Column unknown!!!
      std::cerr << "Error, " << column_name << " is unknown" << std::endl;
}



// Question 2-bis
DataFrame::mapped_type
DataFrame::get_column (const key_type & column_name) const
{
    if (check_column_name (column_name))
      return df_data.at(column_name);
    else{
      std::cerr << "Error, " << column_name << " is unknown" << std::endl;
      return std::vector<double> ();
    }
}



// Question 3-bis
double
DataFrame::get_element_at (const key_type & column_name,
                           size_type index) const
{
    if (check_column_name (column_name)){
      if(index < n_rows)
        return df_data.at(column_name)[index];
      else{
        std::cerr << "Error, index out of bound" << std::endl;
        return std::numeric_limits<double>::quiet_NaN();
      }
    }
    else{
      std::cerr << "Error, " << column_name << " is unknown" << std::endl;
      return std::numeric_limits<double>::quiet_NaN();
    }
}



// Question 4
double
DataFrame::get_mean (const key_type & column_name) const
{
    if (check_column_name (column_name))
    { // compute the mean
      double sum = 0.;

      for (double d : df_data.at (column_name))
        sum += d;

      return sum / n_rows;
    }
  else
    {
      std::cerr << "Error, " << column_name << " is unknown" << std::endl;
      return std::numeric_limits<double>::quiet_NaN();
    }
}



// UTILITY for question 5
void
DataFrame::add_column (const key_type & column_name,
                        const mapped_type & column_data)
{
    /* Your code goes here */
}



// Question 5
DataFrame
DataFrame::select_equal (const key_type & c_name,
                          double value) const
{
    /* Your code goes here */

    // check column exists
    if (!check_column_name (c_name)) {// if it doesn return empty DataFrame
      std::cerr << "Error, " << c_name << " is unknown" << std::endl;
      return DataFrame();
    }
	// the column exists so.....
	std::vector<size_type> indexes; // solution indexes
    const mapped_type & relevant_column = df_data.at (c_name);
    // scan all elements of that column and test equality to value
    for (size_type i =0; i < n_rows; ++i){
      if (relevant_column[i] == value)
        indexes.push_back (i);
    }
    // copy these rows into the result DataFrame
    // scan all columns and for each column just select the rows which indeces
    // are indexes
    DataFrame result;
    for (const  value_type & element : df_data){
        mapped_type v; // select the values I'm interested in from the current column
    	v.reserve (indexes.size ()); //v.resize (indexes.size ());
        for (size_type idx : indexes)
          v.push_back (element.second[idx]);//v[idx]=  element.second[idx];

        result.df_data[element.first] = v;  // result.add_column(element.first, v);
    }
    return result;


}
