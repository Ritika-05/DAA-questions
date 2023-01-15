#include <stdio.h>
/* The number of objects */
int n = 5;     
/* c[i] is the *COST* of the ith object; i.e. what  YOU PAY to take the object */               
int c[10] = {12, 2, 5, 2, 8}; 
/* v[i] is the *VALUE* of the ith object; i.e.what YOU GET for taking the object */
int v[10] = {4, 1, 3, 3, 9}; 
 /* The maximum weight you can take */
int W = 15;                  

void simple_fill()
{
    int cur_w;
    float tot_v;
    int i, maxi;
    int used[10];

    for (i = 0; i < n; ++i)
     /* I have not used the ith object yet */
        used[i] = 0;

    cur_w = W;
    while (cur_w > 0)
    { /* while there's still room*/
        /* Find the best object */
        maxi = -1;
        for (i = 0; i < n; ++i)
            if ((used[i] == 0) &&
                ((maxi == -1) || ((float)v[i] / c[i] > (float)v[maxi] / c[maxi])))
                maxi = i;
/* mark the maxi-th object as used */
        used[maxi] = 1;   
/* with the object in the bag, I can carry less */
        cur_w -= c[maxi]; 
        tot_v += v[maxi];
        if (cur_w >= 0)
            printf("Added object %d (%d$, %dKg) completely in the bag. Space left: %d.\n", maxi + 1, v[maxi], c[maxi], cur_w);
        else
        {
            printf("Added %d%% (%d$, %dKg) of object %d in the bag.\n", (int)((1 + (float)cur_w / c[maxi]) * 100), v[maxi], c[maxi], maxi + 1);
            tot_v -= v[maxi];
            tot_v += (1 + (float)cur_w / c[maxi]) * v[maxi];
        }
    }

    printf("Filled the bag with objects worth %.2f$.\n", tot_v);
}

int main(int argc, char *argv[])
{
    simple_fill();

    return 0;
}