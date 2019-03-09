#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<algorithm>

bool check(std::string temp1, std::string temp2)
{
  return temp1 == temp2;
}
std::string cal(std::string date, std::vector<std::string> product, std::vector<std::string> customer)
{
  std::string str{};
  std::vector<std::string>::iterator product_ip{};
  std::vector<std::string>::iterator customer_ip{};

  std::sort(product.begin(), product.end());
  product_ip = std::unique(product.begin(), product.end());
  product.resize(std::distance(product.begin(), product_ip));

  std::sort(customer.begin(), customer.end());
  customer_ip = std::unique(customer.begin(), customer.end());
  customer.resize(std::distance(customer.begin(), customer_ip));


  for(auto i:product)
  str = "[" + date + "]" + " " + std::to_string(product.size()) + " " + std::to_string(customer.size()) + '\n';
  return str;
}

int main(){
  std::ifstream inFile{"db.txt"};
  char ch{};
  std::string date {};
  std::string time{};
  std::string product_id{};
  std::string customer_id{};
  std::vector<std::string> vec_product_id {};
  std::vector<std::string> vec_customer_id{};
  std::string temp_date{};
  std::vector<std::string> result {};
  std::ofstream outFile{"dbnew.txt"};
  
  if(!inFile)
    std::cout << "ERROR" << std::endl;
  
  inFile >> ch >> date >> time >> product_id >> customer_id;
  
  temp_date = date;
  vec_product_id.push_back(product_id);
  vec_customer_id.push_back(customer_id);
  
  do
   {
  	  inFile >> ch >> date >> time >> product_id >> customer_id;
    
   	 if(check(date, temp_date))
   	 {
   	   vec_product_id.push_back(product_id);
   	   vec_customer_id.push_back(customer_id);
   	 }
   	 else if(!check(date, temp_date))
   	 {
   	   result.push_back(cal(temp_date, vec_product_id, vec_customer_id));
   	   temp_date = date;
   	   vec_product_id.clear();
   	   vec_customer_id.clear();
   	   vec_product_id.push_back(product_id);
   	   vec_customer_id.push_back(customer_id);
   }
  }while(!inFile.eof());
  result.push_back(cal(temp_date, vec_product_id, vec_customer_id));
  for(auto i:result)
    outFile << i;
  std::cout << "Done, Check new list" << std::endl;
  inFile.close();
  outFile.close();
  return 0;
}
