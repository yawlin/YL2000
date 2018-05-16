//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused

#include <stdio.h>

#define N 40
#define MaxS 10

int n;
int debug=0;
int conf[N][4];
extern int exit(int);

static int win[MaxS][MaxS][MaxS][MaxS];

/*---------------------- Read command lines */
void get_input()
{
    int i, j;
    int a, b, c, d;

    scanf("%d ", &n);
    if ( n == 0 ) { printf("*\n");  exit(0); }
    for ( i=0; i < n; i++) {
   	for ( j=0; j < 4; j++ )
      	    scanf("%d ", &conf[i][j]);
    } // for
    for ( a = 0; a < MaxS; a++ )
    for ( b = 0; b < MaxS; b++ )
    for ( c = 0; c < MaxS; c++ )
    for ( d = 0; d < MaxS; d++ ) win[a][b][c][d] = 2;
    win[0][0][0][1] = 0;
    win[0][0][1][0] = 0;
    win[0][1][0][0] = 0;
    win[1][0][0][0] = 0;

}/*input*/

int Winnable(int a, int b, int c, int d) {

    int aa, bb, cc, dd;

    if ( win[a][b][c][d] < 2 ) return win[a][b][c][d];

    for ( aa = 1; aa < 4 && a-aa >= 0; aa++ )
        if ( Winnable( a-aa, b, c, d ) == 0 )
            return win[a][b][c][d] = 1;
    for ( bb = 1; bb < 4 && b-bb >= 0; bb++ )
        if ( Winnable( a, b-bb, c, d ) == 0 )
            return win[a][b][c][d] = 1;
    for ( cc = 1; cc < 4 && c-cc >= 0; cc++ )
        if ( Winnable( a, b, c-cc, d ) == 0 )
            return win[a][b][c][d] = 1;
    for ( dd = 1; dd < 4 && d-dd >= 0; dd++ )
        if ( Winnable( a, b, c, d-dd ) == 0 )
            return win[a][b][c][d] = 1;
    return win[a][b][c][d] = 0;
}


int main(int argc, char* argv[])
{
        int i, j;
        char str[50];

        get_input();
        if (0)
        printf( "n = %d\n", n);
        // verify
        if (0)
        for ( i = 0; i < n; i++ ) {
   	    for ( j=0; j < 4; j++ )
      	        printf("%d ", conf[i][j]);
            printf("\n");
        }

        if(0)
        for ( i = 0; i < n; i++ ) {
            printf( "win[%d][%d][%d][%d] = %d\n",
                conf[i][0], conf[i][1], conf[i][2], conf[i][3],
                win[ conf[i][0] ][ conf[i][1] ][ conf[i][2] ][ conf[i][3] ]
            );
        }


        for ( i = 0; i < n; i++ ) {
            printf( "Winnable(%d, %d, %d, %d) = %d\n",
                conf[i][0], conf[i][1], conf[i][2], conf[i][3],
                Winnable(conf[i][0], conf[i][1], conf[i][2], conf[i][3])
            );
        }

        if(0)
        for ( i = 0; i < n; i++ ) {
            printf( "win[%d][%d][%d][%d] = %d\n",
                conf[i][0], conf[i][1], conf[i][2], conf[i][3],
                win[ conf[i][0] ][ conf[i][1] ][ conf[i][2] ][ conf[i][3] ]
            );
        }

        return (0);
}
//---------------------------------------------------------------------------


