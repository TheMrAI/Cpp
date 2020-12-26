#include <math.h>
#include <stdio.h>

void clear( int H, int W, char page[H][W] )
{
  for ( int y = 0; y < H; ++y )
  {
    for ( int x = 0; x < W; ++x )
    {
      page[y][x] = ' ';
    }
  }
}

void plot( int H, int W, char page[H][W], char c, double ( *f )( double ) )
{
  for ( int x = 0; x < W; ++x )
  {
    double fx = ( x - W / 2 ) / 4.0;  // NOLINT
    double fy = f( fx );
    int y = ( fy * 4.0 ) + H / 2;  // NOLINT
    if ( y >= 0 && y < H )
    {
      page[y][x] = c;
    }
  }
}

void plot_with_d( int H, int W, char page[H][W], char c, double ( *f )( double, double ), double d )
{
  for ( int x = 0; x < W; ++x )
  {
    double fy = f( x, d );
    int y = ( fy * 4.0 ) + H / 2;  // NOLINT
    if ( y >= 0 && y < H )
    {
      page[y][x] = c;
    }
  }
}

void print( int H, int W, char page[H][W] )
{
  for ( int y = 0; y < H; ++y )
  {
    for ( int x = 0; x < W; ++x )
    {
      putchar( page[y][x] );
    }
    putchar( '\n' );
  }
}

double sin_times_d( double x, double d )
{
  return sin( d * x );
}

int main()
{
  int H = 80;   // NOLINT
  int W = 200;  // NOLINT
  printf( "page height H = ?\n" );
  scanf( "%d", &H );  // NOLINT
  printf( "page width W = ?\n" );
  scanf( "%d", &W );  // NOLINT
  char page[H][W];

  clear( H, W, page );
  printf( "sin(d * x), d = ?\n" );
  double d = 0;
  scanf( "%lf", &d );  // NOLINT

  plot_with_d( H, W, page, '.', sin_times_d, d );
  plot( H, W, page, '+', sin );

  print( H, W, page );
}
