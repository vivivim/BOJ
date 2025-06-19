#include <stdio.h>
#include <math.h>

int pick_ham(int c, int last[], int ham[], int n)
{
     int effect = -2147483648;
     int idx = 0;
     int tmp, tmp2 = 2147483647;;

     if (c)
     {
           for (int i = 0; i < n; i++)
           {
                  if (ham[i])
                  {
                         tmp = ham[i]/((int)pow(2, c));
                         if (tmp > effect || (tmp == effect && ham[i] > ham[idx]))
                         {
                               effect = tmp;
                               idx = i;
                          }
                   }
                  else
                       ;
              }
     }
     else
     {
           for (int i = 0; i < n; i++)
          {
                tmp = ham[i];
                if (tmp && tmp < tmp2)
                {
                     effect = tmp;
                     idx = i;
                }
           }
     }
     return (idx);
}

int coke_effect(int c, int ham)
{
    if (!c)
        return (0);
    else
    {
        int effect = ham/((int)pow(2, c));
        effect = ham - effect;
        return (effect);
    }
}

int cal_last(int last[], int k)
{
     int c = 0;
     for (int i = 0; i < k; i++)
     {
           if (last[i])
                c++;
      }
     return (c);
}

int main(void)
{
     int n, k, l;
     scanf("%d %d %d", &n, &k, &l);

     int ham[n];
     for (int i = 0; i < n; i++)
           scanf("%d", &ham[i]);
     int coke[k];
     for (int i = 0; i < k; i++)
           scanf("%d", &coke[i]);

     int stomach = 0, c = 0, idx = 0, last[k];
     for (int i = 0; i < k; i++)
     {
         last[i] = 0;
     }
     for (int i = 0; i < n; i++)
     {
        for (int j = 0; j < k; j++)
        {
            if (coke[j] == i+1)
            {
                 last[i] = l;
                 c++;
                 coke[j] = 0;
            }
        }
        idx = pick_ham(c, last, ham, n);
        stomach += ham[idx] - coke_effect(c, ham[idx]);
        ham[idx] = 0;
        for (int j = 0; j < k; j++)
        {
            if (last[j])
                last[j] -= 1;
        }
        c = cal_last(last, k);
     }
           
     printf("%d", stomach);
     return (0);
}


