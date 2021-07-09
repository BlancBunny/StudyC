# StudyC
C99 Repository

## [C언어 공부 code](https://github.com/BlancBunny/StudyC/tree/main/InitC)

## [자료구조 학습 code](https://github.com/BlancBunny/StudyC/tree/main/data_Structure)

-----------------------

### [Linked-List + Selection Sort 구현 ](https://github.com/BlancBunny/StudyC/blob/main/InitC/InitC/insertionSort_linkedList.c)

![image](https://user-images.githubusercontent.com/77951828/125027862-f47bdc00-e0c1-11eb-9632-02b6c664c187.png)

<pre>
<code>

/*
	- 삽입 시 정렬 함수 - 
	parameter : 리스트 헤드 포인터 h, 삽입할 노드 newNode
	노드 데이터의 크기를 비교하며 적절한 위치에 노드 삽입
*/
void sortedInsert(HeadNode* h, ListNode* newNode) {
	ListNode* curr; 
	// 헤드 포인터에 삽입될 때
	if (h->head == NULL || h->head->data >= newNode->data) {
		newNode->link = h->head;
		h->head = newNode;
		return;
	}
	curr = h->head;
	while (curr->link != NULL && curr->link->data < newNode->data) {
		curr = curr->link;
	}
	newNode->link = curr->link;
	curr->link = newNode;
}
/*
	- 리스트 삽입 정렬 - 
	비정렬 리스트로부터 노드 하나씩 이동하며 
	sorted 리스트에 정렬하면서 삽입 
	완성된 sorted 리스트를 새로운 리스트로 저장 
*/
void insertionSort(HeadNode* h) {
	HeadNode* sorted = createLinkedList();
	ListNode* curr = h->head;
	while (curr != NULL) {
		ListNode* tmp = curr->link;
		sortedInsert(sorted, curr);
		curr = tmp;
	}
	h->head = sorted->head;
}

</code>
</pre>
