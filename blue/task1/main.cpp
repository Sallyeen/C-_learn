/*
 * @Author: GuoJia
 * @Date: 2022-04-27 14:25
 * @Last Modified by: GuoJia
 * @Last Modified time: 2022-04-28 15:53
 */

#include <iostream> 
#include <cstdlib>  // 为了使用随机函数：srand(),rand()
#include <ctime>    // 为了得到时间：time()
#include <vector>
#include <numeric>  // 为了使用累加：std::accumulate
#include <algorithm>  // 为了统计最小值：min_element

int main()
{
    int degree_;  // 难易程度
    int flag = 0; // 记录答对的题数
    std::vector<int> ans_wrong;  // 记录答错的题目正确答案
    std::vector<int> ans_whole;  // 记录全部正确答案
    std::vector<double> time_;  // 记录每次的答题用时
    std::vector<int> numarr_1;  // 记录题目的第一个数字
    std::vector<int> numarr_2;  // 记录题目的第二个数字
    std::vector<int> idx_wrong;  // 记录答错的题目索引
    std::vector<int> op_;  // 记录运算符

    std::cout << "请输入你想选择的题目难易程度: 2(hard), 1(medium) or 0(easy):\n";
    std::cin >> degree_;

    srand(int(time(0)));  // 随机数种子

    for (int i=0; i<((degree_+1)*10); i++)
    {
        int num_1 = rand()%((degree_+1)*100);
        int num_2 = rand()%((degree_+1)*100);
    
        int ans, ans_in;
        if (num_1 % 4 == 0)
        {
            ans = num_1 + num_2;
            std::cout << "请输入 " << num_1 << " + " << num_2 << " 的答案:\n";
            time_t start = time(0);
            std::cin >> ans_in;
            time_t finish = time(0);
            time_t time = finish - start;
            time_.push_back(double(time));
            op_.push_back(1);
        }
        else if (num_1 % 4 == 1)
        {
            ans = num_1 - num_2;
            std::cout << "请输入 " << num_1 << " - " << num_2 << " 的答案:\n";
            time_t start = time(0);
            std::cin >> ans_in;
            time_t finish = time(0);
            time_t time = finish - start;
            time_.push_back(double(time));
            op_.push_back(2);
        }
        else if (num_1 % 4 == 2)
        {
            ans = num_1 * num_2;
            std::cout << "请输入 " << num_1 << " * " << num_2 << " 的答案:\n";
            time_t start = time(0);
            std::cin >> ans_in;
            time_t finish = time(0);
            time_t time = finish - start;
            time_.push_back(double(time));
            op_.push_back(3);
        }
        else
        {
            ans = num_1 / num_2;
            std::cout << "请输入 " << num_1 << " / " << num_2 << " 的答案:\n";
            time_t start = time(0);
            std::cin >> ans_in;
            time_t finish = time(0);
            time_t time = finish - start;
            time_.push_back(double(time));
            op_.push_back(4);
        }
        ans_whole.push_back(ans);

        if (ans == ans_in)
        {
            printf("Bingo!\n");
            flag = flag + 1;
        }
        else
        {
            ans_wrong.push_back(ans);
            idx_wrong.push_back(i);
            numarr_1.push_back(num_1);
            numarr_2.push_back(num_2);
        }
    } 
    int num_wrong = 10 - flag;
    int score = flag * (100/((degree_+1)*10));
    std::cout << "你答对的题数为: " << flag << "\n"; 
    std::cout << "你答错的题数为: " << num_wrong << "\n"; 
    std::cout << "你的最终分数为: " << score << "\n";
    std::cout << "全部正确答案为: " << "\n";    
    for(int i=0; i<ans_whole.size(); i++)
    {
        std::cout<<ans_whole[i]<<"\t";
    }
    std::cout << "\n" << "你答错的题目的正确答案为: " << std::endl;
    for (int i=0; i<idx_wrong.size(); i++)
    {
        switch (op_[i])
        {
            case 1:
                std::cout << numarr_1[i] << " + " << numarr_2[i] << " = " << ans_wrong[i] << "\t";
                break;
            case 2:
                std::cout << numarr_1[i] << " + " << numarr_2[i] << " = " << ans_wrong[i] << "\t";
                break;
            case 3:
                std::cout << numarr_1[i] << " * " << numarr_2[i] << " = " << ans_wrong[i] << "\t";
                break;
            case 4:
                std::cout << numarr_1[i] << " / " << numarr_2[i] << " = " << ans_wrong[i] << "\t";
                break;
        }        
    }


    // std::cout << "你答错的题目的正确答案为: " << "\n";
    // for(int i=0; i<ans_wrong.size(); i++)
    // {
    //     std::cout<<ans_wrong[i]<<"\t";
    // }

    
    // 计算平均用时与最短用时
    double sum_ = std::accumulate(std::begin(time_), std::end(time_), 0.0);
    double avg_ = sum_ / time_.size();
    std::cout << "\n" << "平均用时: " << avg_ << " 秒\n";

    double min_ = *min_element(time_.begin(), time_.end());
    std::cout << "最短用时: " << min_ << " 秒\n";
}