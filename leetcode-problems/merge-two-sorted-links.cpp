#include <iostream>
#include <vector>

// 1. ОПРЕДЕЛЕНИЕ СТРУКТУРЫ (точно как на LeetCode)
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// 2. ВАШЕ БУДУЩЕЕ РЕШЕНИЕ (сюда вы вставите свой алгоритм)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Пока просто возвращаем nullptr, чтобы код компилировался.
        // Здесь будет ваша логика сравнения списков.
        ListNode dummy;
        ListNode* tail = &dummy;
        

        return nullptr; 
    }
};

// 3. ВСПОМОГАТЕЛЬНАЯ ФУНКЦИЯ: Создание списка из массива (вектора)
ListNode* createList(const std::vector<int>& nums) {
    if (nums.empty()) return nullptr;
    
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    
    for (size_t i = 1; i < nums.size(); ++i) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}

// 4. ВСПОМОГАТЕЛЬНАЯ ФУНКЦИЯ: Вывод списка в консоль
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val;
        if (current->next != nullptr) std::cout << " -> ";
        current = current->next;
    }
    std::cout << " -> nullptr" << std::endl;
}

// 5. ТОЧКА ВХОДА (Запуск тестов)
int main() {
    // Создаем тестовые данные (пример №1 из LeetCode)
    ListNode* list1 = createList({1, 2, 4});
    ListNode* list2 = createList({1, 3, 4});

    std::cout << "Исходный список 1: ";
    printList(list1);
    std::cout << "Исходный список 2: ";
    printList(list2);

    // Запускаем ваше решение
    Solution solution;
    ListNode* result = solution.mergeTwoLists(list1, list2);

    std::cout << "Итоговый список:  ";
    printList(result);

    // Примечание: в реальных программах после работы нужно очищать память через delete,
    // но для локальных тестов алгоритмов этим часто пренебрегают, так как ОС очистит память при закрытии.
    return 0;
}
