//���ʵ�ֺ��� y=x+10*sin(10x��+5*cos��5x��������[0,100]�ϵ����ֵ����Сֵ 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define sizepop 101 // ��Ⱥ��Ŀ
#define maxgen 500 // ��������
#define pc 0.6 // �������
#define pm 0.1 // �������
#define lenchrom 20 // Ⱦɫ�峤��
#define bound_down 0 // �����½�
#define bound_up 100 // �Ͻ�
double chrom[sizepop][lenchrom]; // ��Ⱥ����
double fitness[sizepop]; //��Ⱥÿ���������Ӧ��
double fitness_prob[sizepop]; // ÿ�����屻ѡ�еĸ���(ʹ�����̶ķ�ȷ��)
//double bestfitness[maxgen]; // ÿһ������ֵ
//double best_pos[lenchrom]; // ȡ����ֵ��λ��
//double average_best[maxgen+1]; // ÿһ��ƽ������ֵ
double best; // ���н����е�����ֵ
int best_index; // ȡ������ֵ�ĵ����������

// Ŀ�꺯��
double fit_func(double * arr)
{
    double x = *arr;
    double func_result =x+10*sin(10x)+5*cos(5x); 
    return func_result;
}
// ����Ӧ�Ⱥͺ���
double sumfitness(double * fitness)
{
    double sum_fit = 0;
    for(int i=0;i<sizepop;i++)
        sum_fit += *(fitness+i);
    return sum_fit;
}
// ����Сֵ������ͨ����Ӧ�� 
double * min(double * fitness)
{
    double min_fit = *fitness;
    double min_index = 0;
    static double arr[2];
    for(int i=1;i<sizepop;i++)
    {
        if(*(fitness+i) < min_fit)
        {
            min_fit = *(fitness+i);
            min_index = i;
        }
    }
    arr[0] = min_index;
    arr[1] = min_fit;
    return arr;
}
// ��Ⱥ��ʼ��
void init_chrom()
{
    for(int i=0;i<sizepop;i++)
    {
        for(int j=0;j<lenchrom;j++)
        {
            chrom[i][j] = bound_up*(((double)rand())/RAND_MAX);
        }
        fitness[i] = fit_func(chrom[i]); // ��ʼ����Ӧ��
    }
}
// ѡ���������С�� 
void select_min(double chrom[sizepop][lenchrom])
{
    int index[sizepop];
    for(int i=0;i<sizepop;i++)
    {
        double * arr = chrom[i];
        fitness[i] = 1/(fit_func(arr)); // ����Сֵ����Ӧ��ΪĿ�꺯���ĵ�����������ֵԽС����Ӧ��Խ��
    }
    double sum_fitness = 0;
    for(int i=0;i<sizepop;i++)
    {
        sum_fitness += fitness[i]; // ��Ӧ�����
    }
    for(int i=0;i<sizepop;i++)
    {
        fitness_prob[i] = fitness[i]/sum_fitness;
    }
    for(int i=0;i<sizepop;i++)
    {
        fitness[i] = 1/fitness[i]; // �ָ�����ֵ
    }
    for(int i=0;i<sizepop;i++) // sizepop �����̶�
    {
        double pick = ((double)rand())/RAND_MAX;
        while(pick < 0.0001)
            pick = ((double)rand())/RAND_MAX;
        for(int j=0;j<sizepop;j++)
        {
            pick = pick - fitness_prob[j];
            if(pick<=0)
            {
                index[i] = j;
                break;
            }

        }
        
    }
    for(int i=0;i<sizepop;i++)
    {
        for(int j=0;j<lenchrom;j++)
        {
            chrom[i][j] = chrom[index[i]][j];
        }
        fitness[i] = fitness[index[i]];
    }
}
// ѡ���������� 
void select_max(double chrom[sizepop][lenchrom])
{
    int index[sizepop];
    for(int i=0;i<sizepop;i++)
    {
        double * arr = chrom[i];
        fitness[i] = fit_func(arr); // �����ֵ����Ӧ��ΪĿ�꺯������������ֵԽ����Ӧ��Խ��
    }
    double sum_fitness = 0;
    for(int i=0;i<sizepop;i++)
    {
        sum_fitness += fitness[i]; // ��Ӧ�����
    }
    for(int i=0;i<sizepop;i++)
    {
        fitness_prob[i] = fitness[i]/sum_fitness;
    }
    for(int i=0;i<sizepop;i++)
    {
        fitness[i] = 1/fitness[i]; // �ָ�����ֵ
    }
    for(int i=0;i<sizepop;i++) // sizepop �����̶�
    {
        double pick = ((double)rand())/RAND_MAX;
        while(pick < 0.0001)
            pick = ((double)rand())/RAND_MAX;
        for(int j=0;j<sizepop;j++)
        {
            pick = pick - fitness_prob[j];
            if(pick<=0)
            {
                index[i] = j;
                break;
            }

        }
        
    }
    for(int i=0;i<sizepop;i++)
    {
        for(int j=0;j<lenchrom;j++)
        {
            chrom[i][j] = chrom[index[i]][j];
        }
        fitness[i] = fitness[index[i]];
    }
}
// �������
void cross(double chrom[sizepop][lenchrom])
{
    for(int i=0;i<sizepop;i++)
    {
        // ���ѡ������Ⱦɫ����н���
        double pick1 = ((double)rand())/RAND_MAX;
        double pick2 = ((double)rand())/RAND_MAX;
        int choice1 = (int)(pick1*sizepop);// ��һ�����ѡȡ��Ⱦɫ�����
        int choice2 = (int)(pick2*sizepop);// �ڶ���Ⱦɫ�����
        while(choice1 > sizepop-1)
        {
            pick1 = ((double)rand())/RAND_MAX;
            choice1 = (int)(pick1*sizepop); //��ֹѡȡλ�ù���
        }
        while(choice2 > sizepop-1)
        {
            pick2 = ((double)rand())/RAND_MAX;
            choice2 = (int)(pick2*sizepop);
        }
        double pick = ((double)rand())/RAND_MAX;// �����ж��Ƿ���н������
        if(pick>pcross)
            continue;
        int flag = 0; // �жϽ����Ƿ���Ч�ı��
        while(flag == 0)
        {
            double pick = ((double)rand())/RAND_MAX;
            int pos = (int)(pick*lenchrom);
            while(pos > lenchrom-1)
            {
                double pick = ((double)rand())/RAND_MAX;
                int pos = (int)(pick*lenchrom); // ����Խ��
            }
            // ���濪ʼ
            double r = ((double)rand())/RAND_MAX;
            double v1 = chrom[choice1][pos];
            double v2 = chrom[choice2][pos];
            chrom[choice1][pos] = r*v2 + (1-r)*v1;
            chrom[choice2][pos] = r*v1 + (1-r)*v2; // �������
            if(chrom[choice1][pos] >=bound_down && chrom[choice1][pos]<=bound_up && chrom[choice2][pos] >=bound_down && chrom[choice2][pos]<=bound_up)
                flag = 1; // ������Ч���˳����棬���������һ�ν���

        }

    }
}
// �������
void mutation(double chrom[sizepop][lenchrom])
{
    for(int i=0;i<sizepop;i++)
    {
        double pick = ((double)rand())/RAND_MAX; // ���ѡ��һ��Ⱦɫ����б���
        int choice = (int)(pick*sizepop);
        while(choice > sizepop-1)
        {
            pick = ((double)rand())/RAND_MAX;
            int choice = (int)(pick*sizepop);  // �����±�Խ��
        }
        pick = ((double)rand())/RAND_MAX; // ���ھ��������Ƿ���б���
        if(pick>pmutation)
            continue;
        pick = ((double)rand())/RAND_MAX;
        int pos = (int)(pick*lenchrom);
        while(pos > lenchrom-1)
        {
            pick = ((double)rand())/RAND_MAX;
            pos = (int)(pick*lenchrom);
        }
        double v = chrom[i][pos];
        double v1 = v - bound_up;
        double v2 = bound_down - v;
        double r = ((double)rand())/RAND_MAX;
        double r1 = ((double)rand())/RAND_MAX;
        if(r >= 0.5)
            chrom[i][pos] = v - v1*r1*(1-((double)i)/maxgen)*(1-((double)i)/maxgen);
        else
            chrom[i][pos] = v + v2*r1*(1-((double)i)/maxgen)*(1-((double)i)/maxgen); // ע������д���ǲ���Խ��ģ�����ֻ��һ�α���Ϳ�����
    }
}
int main(void)
{
    time_t start,finish;
    start = clock(); // ����ʼ��ʱ
    srand((unsigned)time(NULL)); // ��ʼ�����������
    init_chrom(); // ��ʼ����Ⱥ
    double * best_fit_index = min(fitness);
    int best_index =(int)(*best_fit_index);
    gbest = *(best_fit_index+1); // ����ֵ
    gbest_index = 0;
    average_best[0] = sum(fitness)/sizepop; //��ʼƽ������ֵ
    for(int i=0;i<lenchrom;i++)
        gbest_pos[i] = chrom[best_index][i];
    // ������ʼ
    for(int i=0;i<maxgen;i++)
    {
        select_min(chrom); // ѡ��
        cross(chrom); //����
        mutation(chrom); //����
        for(int j=0;j<sizepop;j++)
        {
            fitness[j] = fit_func(chrom[j]);
        }
        double sum_fit = sum(fitness);
        average_best[i+1] = sum_fit/sizepop; // ƽ������ֵ
        double * arr = min(fitness);
        double new_best = *(arr+1);
        int new_best_index = (int)(*arr); // ������ֵ���
        if(new_best < best)
        {
            best = new_best;
            for(int j=0;j<lenchrom;j++)
            {
                best_pos[j] = chrom[new_best_index][j];
            }
            best_index = i+1;
        }

    }
    printf("�Ŵ��㷨������%d�Σ�����ֵΪ:%lf,����ֵ�ڵ�%d��ȡ��,�˴���ƽ������ֵΪ%lf.\n",maxgen,best,best_index,average_best[best_index]);
    printf("ȡ������ֵ�ĵط�Ϊ(%lf,%lf,%lf,%lf,%lf).\n",best_pos[0],best_pos[1],best_pos[2],best_pos[3],best_pos[4]);
    
	    select_max(chrom); // ѡ��
        cross(chrom); //����
        mutation(chrom); //����
        for(int j=0;j<sizepop;j++)
        {
            fitness[j] = fit_func(chrom[j]);
        }
        double sum_fit = sum(fitness);
        average_best[i+1] = sum_fit/sizepop; // ƽ������ֵ
        double * arr = min(fitness);
        double new_best = *(arr+1);
        int new_best_index = (int)(*arr); // ������ֵ���
        if(new_best < best)
        {
            best = new_best;
            for(int j=0;j<lenchrom;j++)
            {
                best_pos[j] = chrom[new_best_index][j];
            }
            best_index = i+1;
        }

    }
    finish = clock(); // ����������
    double duration = ((double)(finish-start))/CLOCKS_PER_SEC;
    printf("��������ʱ:%lf��\n.",duration);
    printf("�Ŵ��㷨������%d�Σ�����ֵΪ:%lf,����ֵ�ڵ�%d��ȡ��,�˴���ƽ������ֵΪ%lf.\n",maxgen,best,best_index,average_best[best_index]);
    printf("ȡ������ֵ�ĵط�Ϊ(%lf,%lf,%lf,%lf,%lf).\n",best_pos[0],best_pos[1],best_pos[2],best_pos[3],best_pos[4]);
    return 0;
}
