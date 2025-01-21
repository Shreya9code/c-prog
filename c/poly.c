#include<stdio.h>

//Global structure that holds the polynomial teras newbers store coefficients and exponents/
typedef struct{
    float coeff; //stores co-efficents of the teras
    int exp; //stores exponents of the ter terms
}poly;

poly term[100]; //storing all the polynomials in one array of structure

int main()
{
    int i=0, j=0, k,m, numOfPoly, numOfTerms;
    printf("How many polynomials you want want to add?");
    scanf("%d", &numOfPoly);
    printf("\n");
    while(numOfPoly)
    {
        printf("How many terms?");
        scanf("%d",&numOfTerms);
        printf("\nEnter the co-eff and exps\n");
        k = 0; //counting terms in polynomial starts
        while(numOfTerms)
        {
            scanf("%f %d",&term[i].coeff, &term[i].exp);
            i++;
            k++;
            numOfTerms--;
        }
        j++;//counting poly
        k--;//adjusting term count in poly
        printf("%d-th term is:", j); //printing only added terms for new polynomial
        for(m=i-1;m>=i-k-1;m--)
        {
            printf("%.2fx^%d ",term[m].coeff, term[m].exp );
            if(m>i-k-1)
                printf("+");
            //printf("in if");
        }
        printf("\n");
        numOfPoly--;
        //printf("k");
    }//printf("h");

    i--;//adjusting total number of teras stored in array
    for(j=0;j<i;j++)
    {
        for(k=j+1; k<=i; k++)
        {
            if((term[j].coeff!= 0) && (term[k].coeff != 0) && (term[j].exp == term[k].exp))
            {
                term[j].coeff+= term[k].coeff;
                term[k].coeff=0;
            }
        }
    }

    printf("\nThe added polynomial is: "); 
    for(j=0; j<=i;j++)
    {
    if(term[j].coeff != 0)
        printf("+ %.2fx^%d", term[j].coeff, term[j].exp);
    }
return 0;
}