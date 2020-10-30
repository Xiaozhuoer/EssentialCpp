/*
--------------------------------------------------------

   BubbleSort冒泡排序算法
        主要是以两个形成嵌套的for循环实现。
        外层的for循环依次以ix值遍历vector的元素，ix的值由
    0递增至size-1。主要的想法是，当外层的for循环每次迭代完
    成，由ix索引出来的元素便已被放置在适当位置。当ix为0时，
    vector中的最小元素会被找到，并被置于位置0处。当ix的值为
    1时，次小的元素会被找到并放在正确位置，以此类推。放置元
    素的操作由内层的for循环完成。jx从ix+1依次递增至size-1；
    它比较位于ix处及jx处的两个元素，如果jx处的元素比较小，就
    将两元素互换

--------------------------------------------------------
*/

#include <iostream>
#include <vector>

using namespace std;



void display(const vector<int> &);
void swap(int &, int &);
void bubblesort(vector<int> &);

int main() {
    int ia[8] = { 8, 34, 3, 13, 1, 21, 5, 2 };
    vector<int> vec(ia, ia + 8);

    cout << " vector before sort: ";
    display(vec);

    bubblesort(vec);

    cout << " vector after sort: ";
    display(vec);
}

void display(const vector<int> &vec) {
    for (int ix = 0; ix < vec.size(); ++ix) {
        cout << vec[ix] << ' ';
    }
    cout << endl;
}

void swap(int &val1, int &val2) {
    int temp = val1;
    val1 = val2;
    val2 = temp;
}

void bubblesort(vector<int> &vec) {
    for (int ix = 0; ix < vec.size(); ++ix) {
        for (int jx = ix + 1; jx < vec.size(); ++jx) {
            if (vec[ix] > vec[jx]) {
                swap(vec[ix], vec[jx]);
            }
        }
    }
}
