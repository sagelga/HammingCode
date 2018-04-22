#include <stdio.h>
#include <math.h>
int main()
{
	int sizeex,size,i,j,input[100],k,count,binary[10],m,ans,encode[100];
	printf("Enter bits size of input in form 2^n (4bit-16bit):\n");
	scanf("2^%d",&sizeex);
	size = pow(2,sizeex)+(sizeex+1);
	//Don't count
	input[0] = 0;
	//Set Parity
	for(i=0;i<=sizeex;i++)//correct
	{
		j = pow(2,i);
		input[j] = 0;
	}
	printf("Enter bits index of input one by one:\n");
	//Set Index Message
	for(i=size;i>=1;i--)//correct
	{
		if(i!=pow(2,0)&&i!=pow(2,1)&&i!=pow(2,2)&&i!=pow(2,3)&&i!=pow(2,4))
		{
			scanf("%d",&input[i]);
		}

	}
	//Change Parity
    //Parity Position:2^0
    for(k=1;k<=size;k++)//pass
    {
        if(k==1||k==3||k==5||k==7||k==9||k==11||k==13||k==15||k==17||k==19||k==21||k==23)
        {
            if(input[k] == 1)//count
            {
                count += 1;
            }
        }
    }
    if(count%2 != 0)//check
    {
        input[1] = 1;
    }
    count =0;
    //Parity Position:2^1
    for(k=2;k<=size;k++)
    {
        if(k==2||k==3||k==6||k==7||k==10||k==11||k==14||k==15||k==18||k==19||k==22||k==23)
        {
            if(input[k] == 1)
            {
                count += 1;
            }
        }
    }
    if(count%2 != 0)//check
    {
        input[2] = 1;
        
    }
    count =0;
    //Parity Position:2^2
    for(k=4;k<=size;k++)
    {
        if(k==4||k==5||k==6||k==7||k==12||k==13||k==14||k==15||k==20||k==21||k==22||k==23)
        {
            if(input[k] == 1)
            {
                count += 1;
            }
        }
    }
    if(count%2 != 0)//check
    {
        input[4] = 1;
        
    }
    count =0;
    //Parity Position:2^3
    if(sizeex > 2)
    {
        for(k=8;k<=size;k++)
        {
            if(k==8||k==9||k==10||k==11||k==12||k==13||k==14||k==15||k==24)
            {
                if(input[k] == 1)
                {
                    count += 1;
                }
            }
        }
        if(count%2 != 0)//check
        {
            input[8] = 1;
        
        }
        count =0;
    }
    //Parity Position:2^4
    if(sizeex > 3)
    {
       for(k=16;k<=size;k++)
        {
            if(k==16||k==17||k==18||k==19||k==20||k==21||k==22||k==23||k==24)
            {
                if(input[k] == 1)
                {
                    count += 1;
                }
            }
        }
        if(count%2 != 0)//check
        {
            input[16] = 1;
        
        }
        count =0; 
    }
	//Show Encoding Message
	printf("Encoding message:\n");
	for(i=size;i>=1;i--)
	{
		printf("%d",input[i]);
	}
    printf("\n");
	//Check Error&Fix
    printf("Enter Encode message one by one:\n");
    //Set Index Message
    for(i=size;i>=1;i--)
    {
        scanf("%d",&encode[i]);
    }
    //Parity Position:2^0
    for(k=1;k<=size;k++)//pass
    {
        if(k==1||k==3||k==5||k==7||k==9||k==11||k==13||k==15||k==17||k==19||k==21||k==23)
        {
            if(encode[k] == 1)//count
            {
                count += 1;
            }
        }
    }
    if(count%2 != 0)//check
    {
        binary[0] = 1;
    }
    else
    {
        binary[0] = 0;
    }
    count =0;
    //Parity Position:2^1
    for(k=2;k<=size;k++)
    {
        if(k==2||k==3||k==6||k==7||k==10||k==11||k==14||k==15||k==18||k==19||k==22||k==23)
        {
            if(encode[k] == 1)
            {
                count += 1;
            }
        }
    }
    if(count%2 != 0)//check
    {
        binary[1] = 1;
        
    }
    else{
        binary[1] = 0;
    }
    count =0;
    //Parity Position:2^2
    for(k=4;k<=size;k++)
    {
        if(k==4||k==5||k==6||k==7||k==12||k==13||k==14||k==15||k==20||k==21||k==22||k==23)
        {
            if(encode[k] == 1)
            {
                count += 1;
            }
        }
    }
    if(count%2 != 0)//check
    {
        binary[2] = 1;
        
    }
    else{
        binary[2] = 0;
    }
    count =0;
    //Parity Position:2^3
    if(sizeex > 2)
    {
        for(k=8;k<=size;k++)
        {
            if(k==8||k==9||k==10||k==11||k==12||k==13||k==14||k==15||k==24)
            {
                if(encode[k] == 1)
                {
                    count += 1;
                }
            }
        }
        if(count%2 != 0)//check
        {
            binary[3] = 1;
        
        }
        else
        {
            binary[3] = 0;
        }
        count =0;
    }
    //Parity Position:2^4
    if(sizeex > 3)
    {
       for(k=16;k<=size;k++)
        {
            if(k==16||k==17||k==18||k==19||k==20||k==21||k==22||k==23||k==24)
            {
                if(encode[k] == 1)
                {
                    count += 1;
                }
            }
        }
        if(count%2 != 0)//check
        {
            binary[4] = 1;
        
        }
        else
        {
            binary[4] = 0;
        }
        count =0; 
    }
    //print error position:
    ans = 0;
    for(i=sizeex;i>=0;i--)
    {
        m = pow(2,i);
        ans+= binary[i]*m;
    }
    if(ans ==0)
    {
        printf("No data error\n");
    }
    else
    {
        printf("Error\n");
        printf("Correct data is:");
        for(i=size;i>=1;i--)
        {
             printf("%d",input[i]);
        }
    }
	return 0;
}