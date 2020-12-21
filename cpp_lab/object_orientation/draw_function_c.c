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
    double fx = ( x - W / 2 ) / 4.0;
    double fy = f( fx );
    int y = ( fy * 4.0 ) + H / 2;
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
    // double fx = (x - W / 2) / 4.0;
    double fy = f( x, d );
    int y = ( fy * 4.0 ) + H / 2;
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
  int H;
  int W;
  printf( "page height H = ?\n" );
  scanf( "%d", &H );
  printf( "page width W = ?\n" );
  scanf( "%d", &W );
  char page[H][W];

  clear( H, W, page );
  printf( "sin(d * x), d = ?\n" );
  double d;
  scanf( "%lf", &d );

  plot_with_d( H, W, page, '.', sin_times_d, d );
  plot( H, W, page, '+', sin );

  print( H, W, page );
}
