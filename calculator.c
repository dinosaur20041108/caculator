/*国家网络安全学院 陈易东 2023302181251 主函数位于末尾*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
//版本定义区
#define version "4.0"
//精度宏定义区
#define addMAX 100001//高精度加法精度
#define minusMAX 100000//高精度减法精度
#define multiMAX 1000//高精度乘法精度
#define diviMAX 10000//高精度除法精度
#define MAX_N 30000 //定义斐波那契数列序列最大值
//颜色宏定义区
#define run color(10)//功能标签颜色
#define choose SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9|0|8|0)//选择型标签颜色
#define re color(7)//恢复颜色
#define tip SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11|0|8|0)//温馨提示颜色



void color(short x)	//自定义函根据参数改变颜色 
{
    if(x>=0 && x<=15)//参数在0-15的范围颜色
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);	//只有一个参数，改变字体颜色 
    else//默认的颜色白色
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
/*
颜色函数SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),前景色 | 背景色 | 前景加强 | 背景加强);
	前景色：数字0-15 或 FOREGROUND_XXX 表示	（其中XXX可用BLUE、RED、GREEN表示） 
	前景加强：数字8 或 FOREGROUND_INTENSITY 表示
	背景色：数字16 32 64 或 BACKGROUND_XXX 三种颜色表示 
	背景加强： 数字128 或 BACKGROUND_INTENSITY 表示
前景颜色对应值： 
　　0=黑色                8=灰色　　
  　1=蓝色                9=淡蓝色               　　                        
　　2=绿色                10=淡绿色               　　
　　3=湖蓝色              11=淡浅蓝色     　
　　4=红色                12=淡红色       　　
　　5=紫色                13=淡紫色             　　
　　6=黄色                14=淡黄色              　　
　　7=白色                15=亮白色      
*/

//iexit非法字符退出函数
void iexit(){
    re;
    color(12);
    printf("输入存在非法字符！");
    color(8);
    printf("\n即将自动返回菜单！\n");
    color(16);
    system("PAUSE");
}


//1.>----------------------科学计算器----------------------<
void easy(){
    int select;// 选择的简单计算器功能
    double a, b;// 定义算术的两个数
    int c;
    color(14);printf(">------------------------科学计算器启动------------------------<\n");
    tip;printf("温馨提示：本功能以科学计数法的形式输出！\n");re;
    color(14);printf("运算列表:1.加 2.减 3.乘 4.除\n");
    choose;printf("请选择功能:");re;
            scanf("%d", &select);
            while (select < 1 || select > 4) {// 只允许选择菜单栏内的数字，体现安全性
            color(12);printf("请输入合理的选项!\n");re;
            choose;printf("请请重新选择菜单功能:");re;
            scanf("%d",&select);
        }
    run;printf("请输入第一个数：");re;
    c=scanf("%lf",&a,&b);
    run;printf("请输入第二个数：");re;
    c=scanf("%lf",&b);
    run;printf("答案为:");color(15);
    switch (select) {
            case 1:
                printf("%e",a+b);
                break;
            case 2:
                printf("%e",a-b);
                break;
            case 3:
                printf("%e", a*b);
                break;
            case 4:
                if (b==0)
                {
                color(4);printf("0不能做除数！");
                }
                else printf("%e",a/b);
                break;
    }
    color(8);printf("\n运算完毕!即将自动返回菜单！\n");re;
    system("PAUSE");
    return;
}

//2.>----------------------高精度加法----------------------<
void add(){
    color(14);printf(">------------------------高精度加法启动------------------------<\n");
    tip;printf("温馨提示：本功能支持%d位以内的正整数相加！\n",addMAX-1);
    printf("若要从txt文件输入请将存有两个数的num.txt放入此文件夹(两个数字换行隔开)\n");
    char s[addMAX],ss[addMAX];
    short int a[addMAX],b[addMAX];
    int len;
    int txt=0;
    char ch;
    run;printf("是否从txt读入(0.否，1.是)：");re;
    scanf("%d",&txt);
    if (txt==1)
    { FILE* fp; 
        if ((fp = fopen("num.txt", "r")) == NULL)
        {
            color(12);printf("读取 num.txt 失败");
            color(8);printf("\n即将自动返回菜单！\n");color(16);
            system("PAUSE");
            return;
        }
        else{
            int i=0;
            
        while(1){//循环读取
            fread(&ch, sizeof(char), 1, fp);
            if (ch==10)//分隔标记
            {
                break;
            }
            s[i]=ch;
            i++;
            }
        fgets(ss, addMAX, fp);
        }
        run;printf("第一个正整数：");re;
        printf("%s\n",s);
		run;printf("第二个正整数：");re;
        printf("%s\n",ss);
        fclose(fp);
	}
    else{
    run;printf("请输入第一个正整数：");re;//字符串形式输入
    scanf("%s",s);
    run;printf("请输入第二个正整数：");re;
    scanf("%s",ss);}
    int l1 = strlen(s);
	int l2 = strlen(ss); 
	if (l1 > l2) 
		len = l1;      
	else 
		len = l2;//len赋值为其中大的数
	memset(a,0,sizeof(a));    //清零
	memset(b,0,sizeof(b));    
	for (int i = l1 - 1 ; i >= 0 ; i--)    //倒过来输入数组
		{
            a[l1 - i - 1] = s[i] - '0';
        if (a[l1-i-1]<0 || a[l1-i-1]>9)
        {
            iexit();return;}//iexit非法字符退出函数
        }        
	for (int i = l2 - 1 ; i >= 0 ; i--)    
		{b[l2 - i - 1] = ss[i] - '0';
        if (0>b[l2-i-1]||b[l2-i-1]>9){
            iexit();return;
            }//iexit非法字符退出函数
        }      

	for (int i = 0 ; i < len ; i++)//进位
	{
		a[i] = a[i] + b[i];    
		a[i+1]+= a[i] / 10;    
		a[i] = a[i] % 10;      
	}
	if (a[len] != 0) len++;    //长度是否增加

	while (a[len - 1] == 0 && len>1)
        len--;	//while去零
	run;printf("答案为：");color(15);
	for (int i = len - 1 ;i >= 0 ;i--)
		printf("%d",a[i]); 
	color(16);printf("\n（tip:此答案共%d位）\n",len);
    
    run;printf("是否将答案保存为txt(0.否，1.是)：");re;
    scanf("%d",&txt);
    if (txt==1)
    {FILE* fp; 
        fp = fopen("ans.txt", "w");  
    if (!fp) {  
        perror("保存为txt失败");  
    }  
    else {
        for (int i = len - 1 ;i >= 0 ;i--)
        fputc(a[i]+48,fp);
        run;printf("答案已保存至ans.txt！");re;
        }
        fclose(fp);
    }
    
    color(8);printf("\n运算完毕!即将自动返回菜单！\n");color(16);
    system("PAUSE");
    return;
}

//3.>----------------------高精度减法----------------------<
void minus()
{   char s[minusMAX],ss[minusMAX];
    short int a[minusMAX],b[minusMAX];//short int节约内存
    color(14);printf(">------------------------高精度减法启动------------------------<\n");
    tip;printf("温馨提示：本功能支持%d位以内的正整数相减！\n",minusMAX);
    printf("若要从txt文件输入请将存有两个数的num.txt放入此文件夹(两个数字换行隔开)\n",addMAX-1);
    int txt=0;
    char ch;
    run;printf("是否从txt读入(0.否，1.是)：");re;
    scanf("%d",&txt);
    if (txt==1)
    { FILE* fp; 
        if ((fp = fopen("num.txt", "r")) == NULL)
        {
            color(12);printf("读取 num.txt 失败");
            color(8);printf("\n即将自动返回菜单！\n");color(16);
            system("PAUSE");
            return;
        }
        else{
            int i=0;
            
        while(1){//循环读取
            fread(&ch, sizeof(char), 1, fp);
            if (ch==10)//分隔标记
            {
                break;
            }
            s[i]=ch;
            i++;
            }
        fgets(ss, addMAX, fp);
        }
        run;printf("第一个正整数：");re;
        printf("%s\n",s);
		run;printf("第二个正整数：");re;
        printf("%s\n",ss);
        fclose(fp);
	}
    else{
    run;printf("请输入第一个正整数：");re;//字符串形式输入
    scanf("%s",s);
    run;printf("请输入第二个正整数：");re;
    scanf("%s",ss);}
    int l1 = strlen(s);    //字符串长度 
    int l2 = strlen(ss);
    int len; 
    int flag = 0;         //一个记录正负的变量
    memset(a,0,sizeof(a));       
    memset(b,0,sizeof(b));  

    if ( l1 < l2 || (strcmp(s,ss) < 0 && l1 == l2) )    //判断前后两数的大小的  
    {                                           
        flag = 1; //把正负记录下来  
        for (int i = l2 - 1 ; i >= 0 ; i--)    //倒过来输入 
            {a[l2 - i - 1] = ss[i] - '0';//将字符串里的字符转换为数字
            if (0>a[l2-i-1]||a[l2-i-1]>9){
                iexit();return;
                }//iexit非法字符退出函数 
            }      
        for (int i = l1 - 1 ; i >= 0 ; i--)
            {b[l1 - i - 1] = s[i] - '0';
            if (0>b[l1-i-1]||b[l1-i-1]>9){
                iexit();return;
                }//iexit非法字符退出函数
            }
    }
    else
    {
        for (int i = l1 - 1 ; i >= 0 ; i--)   
            {a[l1 - i - 1] = s[i] - '0';
            if (0>a[l1-i-1]||a[l1-i-1]>9){
                iexit();return;
                }//iexit非法字符退出函数
            }
        for (int i = l2 - 1 ; i >= 0 ; i--)
            {b[l2 - i - 1] = ss[i] - '0';
            if (0>b[l2 - i - 1]||b[l2 - i - 1]>9){
                iexit();return;
                }//iexit非法字符退出函数
            }
    }
    if (l1 > l2) 
        len = l1;             //len赋值为其中大的数 
    else 
        len = l2; 
    for (int i = 0 ; i < len ; i++)
    {
        a[i] = a[i] - b[i];     //运算 
        if (a[i] < 0)          //如果减得多了 
        {
            a[i+1]-=1;         //向前要一位 
            a[i]+=10;          
        }
    }

    while (a[len - 1] == 0 && len>1) len--;   //while去零
    run;printf("答案为：");color(15);
    if (flag == 1) printf("-");     //如果结果是负的，先输出一个负号 
    for (int i = len - 1 ;i >= 0 ;i--)   //再输出结果 
        printf("%d",a[i]);
    color(16);printf("\n（tip:此答案共%d位）\n",len);

    run;printf("是否将答案保存为txt(0.否，1.是)：");re;
    scanf("%d",&txt);
    if (txt==1)
    {FILE* fp; 
        fp = fopen("ans.txt", "w");  
    if (!fp) {  
        perror("保存为txt失败");  
    }  
    else{
        for (int i = len - 1 ;i >= 0 ;i--)
        fputc(a[i]+48,fp);
        run;printf("答案已保存至ans.txt！");re;
        }
    fclose(fp);  
        
    }

    color(8);printf("\n运算完毕!即将自动返回菜单！\n");color(16);
    system("PAUSE");
    return;
}

//4.>----------------------高精度乘法----------------------<
void multi()
{   char num1[multiMAX];
    char num2[multiMAX];
    color(14);printf(">------------------------高精度乘法启动------------------------<\n");
    tip;printf("温馨提示：本功能支持%d位以内的正整数相乘！\n",multiMAX);
    printf("若要从txt文件输入请将存有两个数的num.txt放入此文件夹(两个数字换行隔开)\n",addMAX-1);
    int txt=0;
    char ch;
    run;printf("是否从txt读入(0.否，1.是)：");re;
    scanf("%d",&txt);
    if (txt==1)
    { FILE* fp; 
        if ((fp = fopen("num.txt", "r")) == NULL)
        {
            color(12);printf("读取 num.txt 失败");
            color(8);printf("\n即将自动返回菜单！\n");color(16);
            system("PAUSE");
            return;
        }
        else{
            int i=0;
             while(1){//循环读取
            fread(&ch, sizeof(char), 1, fp);
            if (ch!=10)//分隔标记
            {
                num1[i]=ch;
                i++;
            }
            else break;
            }
            num1[i]='\0';
        fgets(num2, multiMAX, fp);
        }
        run;printf("第一个正整数：");re;
        printf("%s\n",num1);
		run;printf("第二个正整数：");re;
        printf("%s\n",num2);
        fclose(fp);
	}
    else{
    run;printf("请输入第一个正整数：");re;//字符串形式输入
    scanf("%s",num1);
    run;printf("请输入第二个正整数：");re;
    scanf("%s",num2);}
    int la,lb,lc;
    short int a[multiMAX]={0},b[multiMAX]={0},c[2*multiMAX]={0};//short int节约内存
    la=strlen(num1);
    lb=strlen(num2);
    for(int i=0;i<la;i++)
    {
        a[la-i-1]=num1[i]-'0';//逆序存放
        if (0>a[la-i-1]||a[la-i-1]>9){
            iexit();return;
            }//iexit非法字符退出函数
    }
    for(int i=0;i<lb;i++)
    {
        b[lb-i-1]=num2[i]-'0';
        if (0>b[lb-i-1]||b[lb-i-1]>9){
            iexit();return;
            }//iexit非法字符退出函数
    }
    lc=la+lb;//记录两个字符串的总长度

    for(int i=0;i<la;i++)
    {
        for(int j=0;j<lb;j++)
        {
            c[i+j]+=a[i]*b[j];
            c[i+j+1]+=c[i+j]/10;
            c[i+j]%=10;
        }
    }
    while(c[lc]==0&&lc>0)lc--;
    char *ret=(char *)malloc(sizeof(char)*(lc+2));//malloc创建动态数组并用指针re指向
    for(int i=lc;i>=0;i--){
        ret[lc-i]=c[i]+'0';
    }
    ret[lc+1]=0;
    run;printf("答案为：");color(15);
    printf("%s",ret);
    color(16);printf("\n（tip:此答案共%d位）\n",lc);

    run;printf("是否将答案保存为txt(0.否，1.是)：");re;
    scanf("%d",&txt);
    if (txt==1)
    {FILE* fp; 
        fp = fopen("ans.txt", "w");  
    if (!fp) {  
        perror("保存为txt失败");  
    }  
    else{
        fputs(ret,fp);
        run;printf("答案已保存至ans.txt！");re;
        } 
        fclose(fp);
    }

    color(8);printf("\n运算完毕!即将自动返回菜单！\n");color(16);
    system("PAUSE");
    free(ret);//释放动态数组
}

//5.>----------------------高精度除法----------------------<
/* 用被除数减除数，直到减到其小于除数，减了几次，商就是多少，如果除数和被除数相差较大，那么相减就要花费太多的时间；
本程序采用优化方案：将除数扩大到恰好比被除数小，大大节约了时间。比如；9131和23，将23扩大到2300，再进行减法直到小于除数，减几次就乘以一百，然后在减去减数乘以十，也就是减去230，依此类推；*/
int setZero(short int*num,int len){//将数组清0的函数
	for(int i=0;i<len;i++)
		num[i]=0;
}
int compare(short int*num1,short int*num2){//数字太大且使用多次，需要专门用一个函数比较两个数组形式数字大小
	int i,j;                                //传入数组指针，进行比较
	for(i=diviMAX-1;num1[i]==0;i--);
	for(j=diviMAX-1;num2[j]==0;j--);
	if(i<j)return -1;
	else if(i>j)return 1;
	else{
		for(;i>=0;i--){
			if(num1[i]>num2[i])
				return 1;//大返回1
			else if(num1[i]<num2[i])
				return -1;//小返回-1
		}
		return 0;//相等返回0
	}
}
int copy(short int*num1,short int*num2){//传入数组指针
	int i,j;
	for(i=0;i<diviMAX-1;i++)
		num1[i]=0;
	for(i=diviMAX-1;num2[i]==0;i--);//i成为长度
	for(j=0;j<=i;j++)
		num1[j]=num2[j];//赋值
	return i+1;
}
void divi(){//高精度除法主函数
    char str1[diviMAX];
	char str2[diviMAX];
	color(14);printf(">------------------------高精度除法启动------------------------<\n");
    tip;printf("温馨提示：本功能支持%d位以内的正整数相除！答案由商和余数构成,需要小数请移步高精度小数！\n",diviMAX);
    printf("若要从txt文件输入请将存有两个数的num.txt放入此文件夹(两个数字换行隔开)\n",addMAX-1);
    int txt=0;
    char ch;
    run;printf("是否从txt读入(0.否，1.是)：");re;
    scanf("%d",&txt);
    if (txt==1)
    { FILE* fp; 
        if ((fp = fopen("num.txt", "r")) == NULL)
        {
            color(12);printf("读取 num.txt 失败");
            color(8);printf("\n即将自动返回菜单！\n");color(16);
            system("PAUSE");
            return;
        }
        else{
            int i=0;
            
        while(1){//循环读取
            fread(&ch, sizeof(char), 1, fp);
            if (ch==10)//分隔标记
            {
                break;
            }
            str1[i]=ch;
            i++;
            }
            str1[i]='\0';
        fgets(str2, addMAX, fp);
        }
        run;printf("第一个正整数：");re;
        printf("%s\n",str1);
		run;printf("第二个正整数：");re;
        printf("%s\n",str2);
        fclose(fp);
	}
    else{
    run;printf("请输入第一个正整数：");re;//字符串形式输入
    scanf("%s",str1);
    run;printf("请输入第二个正整数：");re;
    scanf("%s",str2);}
    short int a[diviMAX],b[diviMAX],c[diviMAX];//short int节约内存
	setZero(a,diviMAX);
	setZero(b,diviMAX);
	setZero(c,diviMAX);
	
	int i,j,tmp,tmp2=0,borrow=0;//用于记录扩大倍数
    short int temp[diviMAX]={0},temp2[diviMAX]={0};//short int节约内存，存储已减去数字
	int len1=strlen(str1),len2=strlen(str2);
	for(i=0;i<len1;i++)
		{a[i]=str1[len1-1-i]-'0';//存入数组；
        if (0>a[i]||a[i]>9){
            iexit();return;
            }//iexit非法字符退出函数 
            }  
	for(i=0;i<len2;i++)
		{b[i]=str2[len2-1-i]-'0';
         if (0>b[i]||b[i]>9){
             iexit();return;
             }//iexit非法字符退出函数 
            } 
	
	if(compare(a,b)<0){//判断被除数与除数大小
	run;printf("答案为：");color(15);
    printf("0");
    color(16);printf("\n（tip:此答案共1位）");
    color(8);printf("\n运算完毕!即将自动返回菜单！\n");color(16);
    system("PAUSE");
    return;
	}
	while(compare(a,b)>=0){		        //除完一位循环再除下一位                  	
		tmp=len1-len2;
		if(tmp==tmp2&&tmp>0)
			tmp--;
		tmp2=tmp;//扩大倍数
		
		setZero(temp2,diviMAX);
		for(i=len1-1;i>=tmp;i--)
			temp2[i]=b[i-tmp]; 
		copy(temp,a);
		
		if(compare(temp,temp2)<0)
				continue;
		for(j=1;j++;){
			borrow=0;//借位先定义为零
			for(i=tmp;i<len1;i++){
				temp[i]=a[i]-temp2[i]-borrow;//每一位相减
				if(temp[i]<0){
					borrow=1;
					temp[i]+=10;//不够减借1位后的结果
				}
				else
					borrow=0;//够减
			}
			len1=copy(a,temp);//减完一次，temp（余数）赋给a
			    c[tmp]=j;//商
			if(compare(temp,temp2)<0)//减至，temp（余数）小于减数
				break;
		}
	}
	for(i=diviMAX-1;c[i]==0;i--);//除去高位的零
    for(j=diviMAX-1;a[j]==0;j--);//除去高位的零
    len1=i;//答案长度
    len2=j;//余数长度
    run;printf("商为：");color(15);
	for(;i>=0;i--)
		printf("%d",c[i]);
    run;printf("\n余数为：");color(15);
    for(;j>=0;j--)
		printf("%d",a[j]);
    color(16);printf("\n（tip:此答案共%d位，余数共%d位）\n",len1+1,len2+1);

    run;printf("是否将答案保存为txt(0.否，1.是)：");re;
    scanf("%d",&txt);
    if (txt==1)
    {FILE* fp; 
        fp = fopen("ans.txt", "w");  
    if (!fp) {  
        perror("保存为txt失败");  
    }
    else{  
        i=len1;//答案长度
        j=len2;//余数长度
        fputs("商为：",fp);
        for(;i>=0;i--)
            fputc(c[i]+48,fp);
            fputc(10,fp);
        fputs("余数为：",fp);
        for(;j>=0;j--)
            fputc(a[j]+48,fp);
        run;printf("答案已保存至ans.txt！");re;
        }
    fclose(fp);
    }

    color(8);printf("\n运算完毕!即将自动返回菜单！\n");color(16);
    system("PAUSE");
    return;
}

//6.>----------------------高精度阶乘----------------------<
void fact(){
    short a[99999] = { 1 };
    int i, up, c, s,n,j;
    
    color(14);printf(">----------------------高精度阶乘启动----------------------<\n");
    tip;printf("温馨提示：本功能支持25000以内的正整数阶乘！\n");
    run;printf("请输入正整数：");
    re;scanf("%d", &n);
    while(n>25000||n<0)
    {
        color(12);printf("请输入不大于25000的正整数！\n请重新输入：");re;
        scanf("%d", &n);
    }
    
    c = 1;
    for (i = 1; i <= n; i++)
    {
    up = 0;//进位
    for (j = 0; j < c; j++)//各位乘i
    {
    s = a[j] * i + up;
    a[j] = s % 10;
    up = s / 10;
    }
    while (up)//位数加
    {
    a[c++] = up % 10;
    up /= 10;
    }
    }
    run;printf("答案为：");color(15);
    for (i = c - 1; i >=0 ;i--)
    {
    printf("%d", a[i]);
    
    }
    color(16);printf("\n（tip:%d的阶乘共%d位）\n",n,c);

    int txt;
    run;printf("是否将答案保存为txt(0.否，1.是)：");re;
    scanf("%d",&txt);
    if (txt==1)
    {FILE* fp; 
        fp = fopen("ans.txt", "w");  
    if (!fp) {  
        perror("保存为txt失败");  
    }  
    else{
        for (i = c - 1; i >=0 ;i--)
        {
            fputc(a[i]+48,fp);
        }
        run;printf("答案已保存至ans.txt！");re;
    }
    fclose(fp);  
    }

    color(8);printf("\n运算完毕!即将自动返回菜单！\n");color(16);
    system("PAUSE");
    return;
}

//7.>----------------------高精度小数----------------------<
/* 由于计算机内部表达方式的限制，浮点运算都有精度问题，为了得到高精度的计算结果，就需要自己设计实现方法。
(0,1)之间的任何浮点数都可以表达为两个正整数的商，为了表达这样两个数的商，可以将相除的结果以多个整数来表示，每个整数表示结果的一位。即商的第一位用一个整数来表示，第二位用另一个整数来表示，以此类推，就可以输出一个高精度的除法结果了。
如16/19的结果0.8421052631…就可以依次输出8、4、2、1、0、5、2、6、3、1…。
而除法的过程，则可以模仿人工列竖式做除法的方式，先将被除数乘以10，得到一位商以后，将余数乘以10作为下一轮计算的被除数 */
void floats()
{
	long long a, b;
	color(14);printf(">----------------------高精度小数启动----------------------<\n");
    tip;printf("温馨提示：本功能支持分子和分母在24位以内的分数！\n");
    run;printf("请输入分子/分母（用“/”隔开）：");re;
    scanf("%lld/%lld",&a, &b);
    while(a>LLONG_MAX||b>LLONG_MAX)
    {
        color(12);printf("分子或分母过大！\n请重新输入：");re;
        scanf("%lld/%lld",&a, &b);
    }
	while(b==0)
    {
        color(12);printf("分母为0！\n请重新输入：");re;
        scanf("%lld/%lld",&a, &b);
    }
	int n;
    run;printf("请输入希望得到的小数位数：");re;
    scanf("%d",&n);

    while(n>INT_MAX||n<1)
    {
        color(12);printf("位数过大或小于1！\n请重新输入：");re;
        scanf("%d",&n);
    }
    run;printf("答案为：");color(15);

    if (b>a)
        printf("0.");//真分数输出整数部分0
    if (a>=b)//假分数输出整数部分
    {   
        long long c=a/b;
        printf("%lld.", a/b);
        a %= b;
        
    }
    
	for(int i=1; i<=n; i++)
	{
		a *= 10;
		printf("%d", a/b);//被除数乘以10，得到一位商以后，将余数乘以10作为下一轮计算的被除数
		//if(a%b==0) printf("0");
		a %= b;
	}
    color(8);printf("\n运算完毕!即将自动返回菜单！\n");color(16);
    system("PAUSE");
    
	return ;
}


//8.>----------------------高精度斐波那契----------------------<
typedef struct BigInts{//typedef创建结构体变量
    int len; // 数组长度
    int num[MAX_N]; // 存储每一位的数字
} BigInt;

void init(BigInt* a, int x) { // 将a初始化为x 
    memset(a, 0, sizeof(BigInt));
    a->num[0] = x;
    a->len = 1;
}

void print(BigInt* a,int n) { // 输出BigInt表示的整数
    for (int i = a->len - 1; i >= 0; i--)
        printf("%d", a->num[i]);
    color(16);printf("\n（tip:斐波那契数列第%d项共%d位）\n",n,a->len);

int txt;
    run;printf("是否将答案保存为txt(0.否，1.是)：");re;
    scanf("%d",&txt);
    if (txt==1)
    {FILE* fp; 
        fp = fopen("ans.txt", "w");  
    if (!fp) {  
        perror("保存为txt失败");  
    }  
    else{
        for (int i = a->len - 1; i >= 0; i--)
        fputc( a->num[i]+48,fp);
        run;printf("答案已保存至ans.txt！");re;
    }
    fclose(fp);  
    }
}

BigInt added(BigInt a, BigInt b) { //小型高精度加法程序
    BigInt ans;
    memset(&ans, 0, sizeof(ans));

    int carry = 0;
    for (int i = 0; i < a.len || i < b.len || carry; i++) {
        int sum = carry;//上一次的进位
        if (i < a.len) sum += a.num[i];
        if (i < b.len) sum += b.num[i];
        ans.num[i] = sum % 10;
        carry = sum / 10;//本次进位
        ans.len++;
    }

    return ans;
}

void fib(int n) { //用于计算n个斐波那契数列数
    if (n < 1) {
        color(12);
        printf("输入无效！项数必须大于等于1。\n");
        re;
        return;
    }

    if (n>30000) {
        color(12);
        printf("超出范围！输入须小于等于30000。\n");
        re;
        return;
    };
    BigInt a, b, c;
    init(&a, 1); // 初始化a=1
    init(&b, 1); // 初始化b=1
    run;printf("答案为：");color(15);

    if (n == 1) {
        print(&a,n); // 输出第1个斐波那契数列数
        return;
    }

    if (n == 2) {
        print(&b,n); // 输出第2个斐波那契数列数
        return;
    }

    for (int i = 3; i <= n; i++) {
        c = added(a, b); // 计算c=a+b
        a = b; // 更新a=b
        b = c; // 更新b=c
    }

    print(&c,n); // 输出第n个斐波那契数列数
    return;
}

void fibmain() {
    color(14);printf(">------------------------高精度斐波那契启动------------------------<\n");
    tip;printf("温馨提示：本功能支持斐波那契数列前30000项！\n");
    int n;
    run;printf("请输入要计算的斐波那契数列的项数：");re;
    scanf("%d", &n);
    fib(n);
    color(8);printf("\n运算完毕!即将自动返回菜单！\n");color(16);
    system("PAUSE");
    return ;
}

void help(){
    color(14);printf("—————————————————————————高精度计算器使用说明——————————————————————————\n");re;
    printf("一、本高精度计算器的功能\n"
    "1.科学计算器2.高精度加法3.高精度减法4.高精度乘法5.高精度除法6.高精度阶乘7.高精度小数8.高精度斐波那契\n\n"

    "二、本计算器的使用流程\n"
    "1.在菜单页面选择一个功能选项或直接退出\n"
    "2.功能启动，输入进行运算的数。\n"
    "3.运算完毕，输出结果\n"
    "4.选择下一个功能选项或退出\n\n"

    "三、本计算器各功能的使用方法\n"
    "1.科学计算器\n"
    "本功能以科学计数法的形式输出。\n"
    "进入功能后选择运算列表:1.加 2.减 3.乘 4.除，回车确认。\n"
    "输入第一个数，回车确认。\n"
    "输入第二个数，回车确认。\n"
    "即得到答案，按任意键返回菜单。\n\n"

    "2.高精度加法\n"
    "本功能支持100000位以内的正整数相加！\n"
    "若要从txt文件输入请将存有两个数的num.txt放入此文件夹(注意：两个数字换行隔开)。\n"
    "输入是否从txt读入(0.否，1.是)，回车确认。（非1均默认为否）\n"
    "不从txt读入则输入第一个数，回车确认。输入第二个数，回车确认。\n"
    "得到答案，选择是否将答案保存为txt(0.否，1.是)。（非1均默认为否）\n"
    "选择是则答案保存至文件夹内ans.txt，按任意键返回菜单。\n\n"

    "3.高精度减法\n"
    "本功能支持100000位以内的正整数相减！用法与高精度加法相同。\n\n"

    "4.高精度乘法\n"
    "本功能支持1000位以内的正整数相乘！用法与高精度加法相同。\n\n"

    "5.高精度除法\n"
    "本功能支持10000位以内的正整数相除！答案由商和余数构成,需要小数请移步高精度小数！用法与高精度加法相同。\n\n"

    "6.高精度阶乘\n"
    "本功能支持25000以内的正整数阶乘！\n"
    "输入正整数，回车确认。\n"
    "得到答案，选择是否将答案保存为txt(0.否，1.是)。（非1均默认为否）\n"
    "选择是则答案保存至文件夹内ans.txt，按任意键返回菜单。\n\n"

    "7.高精度小数\n"
    "本功能支持分子和分母在24位以内的分数，包括真分数和假分数！\n"
    "输入分子/分母，回车确认。\n"
    "得到答案，按任意键返回菜单。\n"

    "8.高精度斐波那契\n"
    "本功能支持输出斐波那契数列前30000项！\n"
    "输入要计算的斐波那契数列的项数，回车确认。\n"
    "得到答案，选择是否将答案保存为txt(0.否，1.是)。（非1均默认为否）\n"
    "选择是则答案保存至文件夹内ans.txt，按任意键返回菜单。\n\n"

    "9.帮助\n"
    "显示使用说明\n\n"

    "0.退出\n"
    "退出程序\n"
    );
    color(14);printf("————————————————————————以上为高精度计算器使用说明————————————————————————\n");re;
    color(8);printf("\n显示完毕!即将自动返回菜单！\n");color(16);
    system("PAUSE");
return;

}


//>----------------------主函数----------------------<
int main() {
    int s;// 选择的功能
    color(3); //封面颜色
    printf("\n  /———————————————————[欢迎使用高精度计算器]——————————————————\\ \n");
    printf(" /                                                             \\\n");
    printf("| 高精度计算器           版本：%s           作者：陈易东    \t|\n",version);
    printf("| High-precision calculator                 version：%s   \t|\n",version);
    printf(" \\                                                             /\n");
    printf("  \\———————————————————————————————————————————————————————————/ \n");
    do{color(14);//菜单颜色
    printf("\n  /—————————————————————————功能菜单——————————————————————————\\ \n");
    printf(" /                                                             \\\n");
    printf("|1.科学计算器\t\t2.高精度加法\t\t3.高精度减法\t|\n");
    printf("|4.高精度乘法\t\t5.高精度除法\t\t6.高精度阶乘\t|\n");
    printf("|7.高精度小数\t\t8.高精度斐波那契\t9.帮助\t\t|\n");
    printf("|\t\t\t0.退出\t\t\t\t\t|\n");
    printf(" \\                                                             /\n");
    printf("  \\———————————————————————————————————————————————————————————/ \n");
    choose;printf("\t\t\t请选择菜单功能:");re;
        scanf("%d",&s);
        putchar(10);//换行
        if ((0 == s)) {
            color(14);printf("\n  *——————————————————谢谢使用CTF高精度计算器——————————————————* \n\n");re;
            return 0;
        }
        if (s < 0 || s > 9) {// 只允许选择菜单栏内的数字，体现安全性
            color(12);printf("\t\t\t请输入合理的选项!\n");
            choose;printf("\t\t\t请重新选择菜单功能:");re;
            scanf("%d",&s);
        }
        switch (s) {//分支结构进入对应函数
            case 1:
                easy();
                break;
            case 2:
                add();
                break;
            case 3:
                minus();
                break;
            case 4:
                multi();
                break;
            case 5:
                divi();
                break;
            case 6:
                fact();
                break;
            case 7:
                floats();
                break;
            case 8:
                fibmain();
                break;
            case 9:
                help();
                break;           
            case 0:
                color(14);printf("\n  *——————————————————[谢谢使用高精度计算器]——————————————————* \n\n");re;
                return 0;
        }
    }while(s!=0);
    return 0;
}