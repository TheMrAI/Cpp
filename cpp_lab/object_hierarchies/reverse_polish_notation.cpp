#include <charconv>
#include <iostream>
#include <stack>
#include <string>

auto main() -> int
{
  std::string word;
  std::stack<double> stack;
  while ( std::cin >> word )
  {
    auto result = 0;  // must use int as gcc 9.2 or clang 9.0.0-2 don't support
                      // std::chars_format
    // NOLINTNEXTLINE
    auto [ignore, error_code] = std::from_chars( word.data(), word.data() + word.size(), result );
    if ( error_code == std::errc{} )
    {
      stack.push( static_cast<double>( result ) );
      std::cout << result << std::endl;
    }
    else
    {
      double rhs = stack.top();
      stack.pop();
      double lhs = stack.top();
      stack.pop();
      if ( word == "+" )
      {
        stack.push( lhs + rhs );
      }
      else if ( word == "*" )
      {
        stack.push( lhs * rhs );
      }
      else if ( word == "-" )
      {
        stack.push( lhs - rhs );
      }
      else if ( word == "/" )
      {
        stack.push( lhs / rhs );
      }
      std::cout << stack.top() << std::endl;
    }
  }
  std::cout << "Result: " << stack.top() << std::endl;

  return 0;
}