#include <stdio.h>
#include <stdlib.h>

struct matrix
{
    int *a;
    int n;
};

void set(struct matrix *m, int i, int j, int val)
{
    if (i - j == 1)
        m->a[i - 2] = val; // index cal
    else if (i - j == 0)
        m->a[m->n - 1 + i - 1] = val;
    else if (i - j == -1)
        m->a[2 * (m->n) - 1 + i - 1] = val;
}

void display(struct matrix m)
{
    int i, j;
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            if (i - j == 1)
                printf("%d ", m.a[i - 2]);
            else if (i - j == 0)
                printf("%d ", m.a[m.n - 1 + i - 1]);
            else if (i - j == -1)
                printf("%d ", m.a[2 * (m.n) - 1 + i - 1]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct matrix m;
    int val;
    printf("Enter dimension: ");
    scanf("%d", &m.n);
    m.a = (int *)malloc(m.n * (m.n + 1) / 2 * sizeof(int));

    printf("Enter data: ");
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            scanf("%d", &val);
            set(&m, i, j, val);
        }
    }
    printf("\n\n");
    display(m);

    return 0;
}
