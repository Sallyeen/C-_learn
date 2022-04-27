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

    std::cout << "请输入你想选择的题目难易程度: 2(hard), 1(medium) or 0(easy):\n";
    std::cin >> degree_;

    srand(int(time(0)));  // 随机数种子

    for (int i=0; i<((degree_+1)*10); i++)
    {
        int num_1 = rand()%((degree_+1)*50);
        int num_2 = rand()%((degree_+1)*50);
        int ans, ans_in;
        if (num_1 % 2 == 0)
        {
            ans = num_1 + num_2;
            std::cout << "请输入" << num_1 << "+" << num_2 << "的答案:\n";
            time_t start = time(0);
            std::cin >> ans_in;
            time_t finish = time(0);
            time_t time = finish - start;
            time_.push_back(double(time));
        }
        else {
            ans = num_1 - num_2;
            std::cout << "请输入" << num_1 << "-" << num_2 << "的答案:\n";
            time_t start = time(0);
            std::cin >> ans_in;
            time_t finish = time(0);
            time_t time = finish - start;
            time_.push_back(double(time));
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
        }
    } 
    int num_wrong = 10-flag;
    int score = flag * 2;
    std::cout << "你答对的题数为: " << flag << "\n"; 
    std::cout << "你答错的题数为: " << num_wrong << "\n"; 
    std::cout << "你答错的题目的正确答案为: " << "\n";
    for(int i=0; i<ans_wrong.size(); i++)
    {
        std::cout<<ans_wrong[i]<<"\t";
    }
    std::cout << "\n" << "全部正确答案为: " << "\n";    
    for(int i=0; i<ans_whole.size(); i++)
    {
        std::cout<<ans_whole[i]<<"\t";
    }
    std::cout << "\n" << "你的最终分数为: " << score << "\n";

    // 计算平均用时与最短用时
    double sum_ = std::accumulate(std::begin(time_), std::end(time_), 0.0);
    double avg_ = sum_ / time_.size();
    std::cout << "平均用时: " << avg_ << " 秒\n";

    double min_ = *min_element(time_.begin(), time_.end());
    std::cout << "最短用时: " << min_ << " 秒\n";
}