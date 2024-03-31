#include <stdio.h>
#include <stdlib.h>

struct matrix
{
    int *a;
    int n;
};

// row major

void set(struct matrix *m, int i, int j, int val)
{
    if (i <= j)
        m->a[m->n * (i - 1) - (i - 2) * (i - 1) / 2 + (j - i)] = val; // index cal
}

int get(struct matrix m, int i, int j)
{
    if (i <= j)
        return m.a[m.n * (i - 1) - (i - 2) * (i - 1) / 2 + (j - i)];
    else
        return 0;
}

void display(struct matrix m)
{
    int i, j;
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            if (i <= j)
                printf("%d ", m.a[m.n * (i - 1) - (i - 2) * (i - 1) / 2 + (j - i)]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

// column major

/*
void set(struct matrix *m, int i, int j, int val)
{
    if (i <= j)
        m->a[j*(j-1)/2 + (i-1)] = val;        // index cal
}

int get(struct matrix m, int i, int j)
{
    if (i <= j)
        return m.a[j*(j-1)/2 + (i-1)];
    else
        return 0;
}

void display(struct matrix m)
{
    int i, j;
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            if (i <= j)
                printf("%d ", m.a[j*(j-1)/2 + (i-1)]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}
*/

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
