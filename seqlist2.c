#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElemType;

const int MAXLISTSIZE=180;//预设的存储空间最大容量
typedef struct seqlist
{
    ElemType *data_address; //存储空间基址
    int listlength ;        //当前长度
    int listsize;            //允许的最大存储容量(以sizeof(ElemType)为单位)
}seqlist;                    //俗称顺序表

// 基本操作接口(函数声明)
int ListInsert(seqlist *L,int pos,ElemType e);
int LocateElem(seqlist *L, ElemType e, int (*compare)(ElemType, ElemType));
int ListEmpty(seqlist *L);
int ListFull(seqlist *L);
int UpdateElem(seqlist *L,int pos,ElemType e);
int ListDelete(seqlist *L,int pos);
int ListLength(seqlist *L);
void InitList(seqlist *L);
void PrintList(seqlist *L);
void DestroyList(seqlist *L);
void ClearList(seqlist *L);
ElemType GetElem(seqlist *L,int pos);

//构造一个最大存储容量为maxsize 的空的顺序表L
void InitList(seqlist *L) //
{
    printf("--------Start InitList()--------\n");  
    L->data_address = (ElemType *)malloc( MAXLISTSIZE * sizeof(ElemType) );
    if( L->data_address==NULL ) 
    {
        exit(1);                //存储分配失败,程序退出
    }
    L->listsize = MAXLISTSIZE;    //该顺序表可以存储元素的最大容量
    L->listlength = 0;            //顺序表的初始长度为
    printf("--------End InitList()--------\n");      
}

// 在顺序表L中查找第个值与e 满足判定条件compare()的元素，
// 若找到，则返回其在L 中的位序，否则返回。
int LocateElem(seqlist *L, ElemType e, int (*compare)(ElemType, ElemType))
{
    int i = 1;        // i 的初值为第元素的位序
    ElemType *p = L->data_address;    // p 的初值为第元素的存储位置
    while (i <= L->listlength && !(*compare)(*p++,e))
    {
        ++i;    // 依次进行判定
    }
    if (i <= L->listlength)
    {
        return i;    // 找到满足判定条件的数据元素为第i 个元素
    }else
    {
        return 0;    // 该线性表中不存在满足判定的数据元素
    }
}// LocateElem

//获取pos位置的元素的值 
ElemType GetElem(seqlist *L,int pos)
{
    if(pos<1 || pos > L->listlength)
    {
        printf("GetElem :: pos is illegal.\n");
        exit(1);
    }
    return (L->data_address[pos-1]);
}  

//替换pos位置元素的值
int UpdateElem(seqlist *L,int pos,ElemType e)
{
    if(pos<1 || pos>L->listlength){
        printf("pos is illegal!\n");
        return 0;
    }
    L->data_address[pos-1] = e;
    return 1;
}  

//若存储空间不满且≤pos≤Listlength(L)+1，则在顺序表L的第pos个元素之前插入新的元素e且返回,否则返回.
int ListInsert(seqlist *L,int pos,ElemType e)
{    
    int j;
    if (pos < 1 || pos > L->listlength+1)    // 插入位置不合法,合法位置是(1) 至(表长+1)
    { 
        printf("ListInsert:::Error pos\n");
        return 0;
    }
    if (L->listlength >= L->listsize)        // 当前存储空间已满，无法插入
    {    
        printf("ListInsert:::Error full of Store Space\n");
        return 0;
    }
    for ( j=L->listlength-1; j >= pos-1; --j)
    {
        L->data_address[j+1] = L->data_address[j];    // 插入位置及之后的元素右移,
        //第表长个元素L->data_address[L->listlength-1] 到第pos个元素L->data_address[pos-1]依次向后移
    }                    
    L->data_address[pos-1] = e;        // 插入e
    ++L->listlength;                // 表长增
    return 1;
}

//打印顺序表，十个元素一行
void PrintList(seqlist *L)
{
    int n,i;
    n = ListLength(L);
    printf("*******************************************************************\n");  
    for(i=1;i<=n;++i)
    {
        printf("%6d",GetElem(L,i));
        if((i)%10==0)
            printf("\n");
    }
    printf("\n");  
    printf("*******************************************************************\n");  
}

//求表长，返回表中元素个数
int ListLength(seqlist *L)
{     
    return(L->listlength);   
}

//判断是否相等 
int equal(int x,int y)   
{   
    if(x==y)
    {   
        return 1; 
    }else 
    { 
        return 0;   
    }
}

//清空表元素
void ClearList(seqlist *L)
{     
    L->listlength = 0;   
}

//销毁顺序表
void DestroyList(seqlist *L)
{
    free(L->data_address);   
    L->listlength = 0;
    L->listsize = 0;
}

//判断顺序表是否为空
int ListEmpty(seqlist *L)
{
    if(L->listlength == 0)
    {
        return 1;
    }else
    {
        return 0;
    }
}

//判断顺序表是否已满
int ListFull(seqlist *L)
{
    if(L->listlength==L->listsize)
    {
        return   1;
    }else
    {
        return   0;
    }
}

// 若≤pos≤Listlength(L)，则从顺序表L 中删除第pos 个元素且返回1，否则返回0
int ListDelete(seqlist *L,int pos)
{
    int i;
    if( ListEmpty(L) ){
        printf("ListDelete:::seqlist is Empty!");
        return 0;
    }
    
    if(pos<1 || pos>L->listlength)
    {
        printf("ListDelete:::pos is illegal!");
        return 0;
    }
    
    for(i=pos;i<L->listlength;++i)
    {
        L->data_address[i-1] = L->data_address[i];
    }
    L->listlength--;
    return 1;
}

// 若≤pos≤Listlength(L)，则从顺序表L 中删除第pos 个元素且返回1，否则返回0, *e为被删除元素的值
int ListDeleteE(seqlist *L,int pos,ElemType *e)
{
    int i;
    if( ListEmpty(L) ){
        printf("ListDeleteE:::seqlist is Empty!\n");
        return 0;
    }
    
    if(pos<1 || pos>L->listlength)
    {
        printf("ListDeleteE:::pos is illegal!\n");
        return 0;
    }
    i=pos;
    *e = L->data_address[i-1];//将要删除的值赋给e
    for(;i<L->listlength;++i)
    {
        //从第pos+1个元素(L->data_address[pos])到第表长个元素(L->data_address[L->listlength-1])依次向前移
        L->data_address[i-1] = L->data_address[i]; 
    }
    L->listlength--; //表长减一
    return 1;
}
/*
已知集合A 和B，求两个集合的并集，使A＝A∪B，且B 不再单独存在
将所有在线性表LB中但不在LA中的数据元素插入到LA 中,
算法执行之后，线性表LB 不再存在。
*/
void Union(seqlist *LA, seqlist *LB)
{
    ElemType e;
    int La_len = ListLength(LA);    //求得线性表LA 的长度
    while (ListEmpty(LB) == 0)        //依次处理LB 中元素直至LB 为空表止
    {    
        ListDeleteE(LB,1,&e);        //从LB 中删除第个数据元素并赋给e
        if (LocateElem(LA,e,equal) == 0)
        {
            ListInsert(LA,++La_len,e);// 当LA中不存在和e 值相同的数据元素时进行插入
        }
    }
    DestroyList(LB);// 销毁线性表LB　
}


/* 已知一个"非纯集合" B，试构造一个集合A，使A 中只包含B 中所有值各不相同的数据元素。
 * 构造线性表LA，使其只包含LB中所有值不相同的数据元素,算法不改变线性表LB　
 */
void Purge(seqlist *LA, seqlist *LB)
{
    int i;
    ElemType e;
    int La_len = 0;
    int Lb_len = ListLength(LB);        // 求线性表LB 的长度
    InitList(LA);                        // 创建一个空的线性表LA
    for (i = 1; i <= Lb_len; i++)        // 依次处理LB 中每个元素
    {
        e = GetElem(LB, i);                // 取LB 中第i 个数据元素赋给e
        if (LocateElem(LA, e, equal) == 0)
        {
            ListInsert(LA, ++La_len, e);// 当LA 中不存在和e 值相同的数据元素时进行插入
        }
    } 
} 

/*

  判别两个集合是否相等。
  两个集合相等的充分必要条件是它们具有相同的元素。
  当以线性表表示集合时，两个线性表的长度应该相等，
  且表中所有数据元素都能一一对应，
  但相同的数据元素在各自的线性表中的"位序"不一定相同。
  　　由此，"判别两个线性表中的数据元素是否完全相同"的算法的
  基本思想为：
  首先判别两者的表长是否相等；在表长相等的前提下，
  如果对于一个表中的所有元素，都能在另一个表中找到和它相等的元素的话，
  便可得到"两个线性表表示的集合相等"的结论；
  反之，只要有一个元素在另一个表中不能找到相等元素时，便可得出"不等"的结论。
  
这个算法是否在任何情况下都正确，会不会有例外的情况？ 
当然，这个算法思想还有一个前提是，已知集合符合集合论中的约定"集合中的元素都是彼此相异的"。估计你也想到了吧。　　
    
如果"集合"中的元素不能保证都相异，那么这个问题的算法应如何写？  
除了判别每个LA 中的元素在LB 中都存在之外，还应反过来判别LB 中每个元素都能在LA 中找到相同者。你不妨试试写一下这个算法。     
*/


//若线性表LA 和LB 不仅长度相等，且所含数据元素也相同，则返回TRUE,否则返回FALSE.
int isEqual(seqlist *LA, seqlist *LB)
{
    ElemType e;
    int La_len = ListLength(LA);
    int Lb_len = ListLength(LB);
    if ( La_len != Lb_len )
    {
        return 0; // 两表的长度不等
    }else
    {
        int i = 1;
        while ( i<= La_len )
        {
            e = GetElem( LA, i);    // 取得LA 中一个元素
            if ( LocateElem(LB, e, equal) != 0 )
            {
                i++;    // 依次处理下一个
            }else
            {
                return 0;    // LB中没有和该元素相同的元素
            }
        } 
        return 1;
    } 
}


//主程序体
int main()
{
    int i;
    seqlist L;
    ElemType e;
    InitList(&L);                    //初始化顺序表
    srand((unsigned int)time(0));    //srand(seed)用于给rand()函数设定种子。
    for(i=1;i<=30;++i)
    {
        ListInsert(&L,i,rand()%30);    //插入个元素
    }
    PrintList(&L);
    printf("length:%d, listSize:%d \n",L.listlength,L.listsize);
    if(LocateElem(&L,0,equal) == 0)
    {
        printf("此顺序表中没有元素值为\n");
    }else
    {
        printf("第一个值为的元素位置: %d \n",LocateElem(&L,0,equal));
    }
    return 0;
}

