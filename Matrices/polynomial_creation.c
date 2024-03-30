#include<stdio.h>
#include<stdlib.h>

struct term
{
    int coeff,exp;
};

struct poly
{
    int n;
    struct term *terms;
};

void create(struct poly *p)
{
    printf("Enter no of terms: ");
    scanf("%d",&p->n);
    p->terms=(struct term *)malloc(p->n*sizeof(struct term));

    printf("Enter the  terms: ");
    for(int i=0;i<p->n;i++)
        scanf("%d%d", &p->terms[i].coeff,&p->terms[i].exp);
}

void display(struct poly p)
{
    for(int i=0;i<p.n;i++)
        printf("%dx%d+",p.terms[i].coeff,p.terms[i].exp);
        printf("\n");
}

int main()
{
    struct poly p;
    create(&p);
    display(p);
    return 0;
}