#include <queue>
#include <iostream>

int main(void)
{
    int n, w, l;
    std::cin >> n >> w >> l;

    std::queue<int> tr;
    int tmp;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> tmp;
        tr.push(tmp);
    }

    int time = 0;
    int weight = 0;
    std::queue<int> bridge;
    std::queue<int> times; // 각 트럭의 진입 시간을 저장하는 큐

    while (!tr.empty() || !bridge.empty())
    {
        ++time;

        // 다리에서 트럭 내보내기
        if (!times.empty() && time - times.front() == w)
        {
            weight -= bridge.front();
            bridge.pop();
            times.pop();
        }

        // 다리에 트럭 추가하기
        if (!tr.empty() && weight + tr.front() <= l && bridge.size() < w)
        {
            weight += tr.front();
            bridge.push(tr.front());
            times.push(time);
            tr.pop();
        }
    }

    std::cout << time;
    return 0;
}
