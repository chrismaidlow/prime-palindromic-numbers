#include<iostream>
using std::cout; using std::cin; using std::endl; using std::boolalpha;
#include<string>
using std::string; using std::to_string;
#include<cmath>

const string the_chars = "0123456789abcdef";

string reverse_string(string str)
{
    string new_str = "";
    
    //iterate through str
    for(char ch : str)
    {
        //add character to front of new_str reversing order
         new_str = ch + new_str;  
    }
    
    return new_str;
}

bool is_palindrome(string str)
{
    string reverse_str = reverse_string(str);
    
    //compare reverse_str and new_str
    if(reverse_str == str)
    {
        return true;   
    }
    else
    {
        return false;
    }
}

string long_to_base(long n, long base)
{
    string new_str = "";
    
    while (n > 0)
    {
        //algo supplied by proj4 pdf implementation
        long remains = n % base;
        char to_add = the_chars[remains];
        new_str = to_add + new_str;
        n = (n / base); 
    }
    
    return new_str;
}

bool is_prime(long n)
{
    //iterate through every integer between n & iter if divisible n is not prime
    for(long iter = 2; iter < n; ++iter)
    {
        if (n % iter == 0)
        {
            return false;
        }
    
    }
    
    return true;
}

string is_pal_prime(long n)
{
    //find out if n is prime
    bool prime_num = is_prime(n);
    
    //convert for each base
    string base_2 = long_to_base(n,2);
    string base_10 = long_to_base(n,10);
    string base_16 = long_to_base(n,16);
    
    //check truth values for each base - first base cleared gets returned
    if(prime_num == true and is_palindrome(base_2) == true)
    {
        return "binary-pal-prime";   
    }
    else if(prime_num == true and is_palindrome(base_10) == true)
    {
        return "decimal-pal-prime";
    }
    else if(prime_num == true and is_palindrome(base_16) == true)
    {
        return "hex-pal-prime";
    }
    else
    {
        return "not-pal-prime";   
    }
    
}

int main (){
  long test_num;
  cin >> test_num;
  cout << boolalpha;

  switch(test_num) {

  case 1: {
    string input;
    cin >> input;
    cout << reverse_string(input);
    break;
  }

  case 2:{
    string input;
    cin >> input;
    cout << is_palindrome(input);
    break;
  }

  case 3:{
    long n, base;
    cin >> n >> base;
    cout << long_to_base(n,base);
    break;
  }

  case 4:{
    long n;
    cin >> n;
    cout << is_prime(n);
    break;
  }

  case 5:{
    long n;
    cin >> n;
    cout << is_pal_prime(n);
    break;
  }
    
  } // of switch
}  // of main