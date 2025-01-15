#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 定义链表节点
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 优先队列的比较函数
struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

// 合并k个升序链表
ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

    // 初始化优先队列
    for (auto& head : lists) {
        if (head) {
            minHeap.push(head);
        }
    }

    // 创建虚拟头节点
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;

    // 合并链表
    while (!minHeap.empty()) {
        // 从优先队列中取出最小的节点
        ListNode* node = minHeap.top();
        minHeap.pop();
        // 将 node 添加到合并后的链表中
        current->next = node;
        current = current->next;
        // 如果 node 有下一个节点，将下一个节点加入优先队列
        if (node->next) {
            minHeap.push(node->next);
        }
    }

    // 返回合并后的链表的头节点
    return dummy->next;
}

// 打印链表
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // 创建测试链表
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* list3 = new ListNode(2);
    list3->next = new ListNode(6);

    vector<ListNode*> lists = {list1, list2, list3};

    // 合并链表
    ListNode* mergedList = mergeKLists(lists);

    // 打印合并后的链表
    printList(mergedList);

    return 0;
}