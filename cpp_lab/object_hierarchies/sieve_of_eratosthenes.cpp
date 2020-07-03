#include <iostream>

class Element
{
public:
  Element(): previous{ nullptr }, next{ nullptr }
  {}

  virtual ~Element()
  {
    delete next;
  }

  virtual void process( unsigned value ) = 0;

  Element* previous;
  Element* next;
};

class Dummy final: public Element
{
public:
  void process( unsigned value ) override
  {
    next->process( value );
  }
};

class Sieve final: public Element
{
public:
  explicit Sieve( unsigned prime ): prime{ prime }
  {}

  void process( unsigned value ) override
  {
    if ( value % prime == 0 )
    {
      return;
    }
    next->process( value );
  }

private:
  unsigned prime;
};

class Bucket final: public Element
{
public:
  void process( unsigned value ) override
  {
    std::cout << value << std::endl;
    auto* sieve = new Sieve( value );
    sieve->next = this;
    sieve->previous = previous;
    previous->next = sieve;
    previous = sieve;
  }
};

auto main() -> int
{
  auto start_element = Dummy();
  auto* bucket = new Bucket();

  start_element.next = bucket;
  bucket->previous = &start_element;

  for ( unsigned i = 2; i < 150; ++i )
  {
    start_element.process( i );
  }

  return 0;
}