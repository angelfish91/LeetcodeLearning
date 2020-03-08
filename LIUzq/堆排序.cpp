//*****************************堆排序*******************************//
//这里为什么用int array[] 和int *array 传参都不行，输出都不对，用vector试一下

///不是传参的问题，而是程序里面的bug，见用vector测试中找出的问题
void downAdjust(int *array, int parentIndex, int length) {
	//temp 保存父节点的值
	int temp = array[parentIndex];
	int childIndex = 2 * parentIndex + 1;
	while (childIndex < length)
	{
		if (childIndex + 1 < length && array[childIndex] < array[childIndex + 1]) {
			childIndex++;
		}
		if (array[parentIndex] > array[childIndex])
			break;
		array[parentIndex] = array[childIndex];
		parentIndex = childIndex;
		childIndex = 2 * childIndex + 1;

	}
	array[parentIndex] = temp;
}

void heapSort(int *array) {
	//先把无序堆构建成最大堆
	//int size = sizeof(array) / sizeof(*array);
	int size = 10;
	for (int i = (size - 2)/2; i >= 0; i--) {
		downAdjust(array, i, size);
		//cout << array[i]+" ";
	}
	
	//把最大堆的对顶元素删除（不是完全删除，只是放到堆尾）
	for (int i = (size - 1); i > 0; i--) {
		int temp = array[i];
		array[i] = array[0];
		array[0] = temp;
		//下沉 调整最大堆
		downAdjust(array, 0, i);
	}
}


int main() {
	int array[] = { 1,3,2,6,5,7,8,9,10,0 };
	heapSort(array);

	for (int i = 0; i < 10; i++)
		cout << array[i];
	
	system("pause");
	return 0;
}


/////////////////////用vector试一下的结果/////////////////////////////
//*****************************堆排序*******************************//

void downAdjust(vector<int> &array, int parentIndex, int length) {		//这里的array要用&传参！！！！
	//temp 保存父节点的值
	int temp = array[parentIndex];
	int childIndex = 2 * parentIndex + 1;
	while (childIndex < length)
	{
		if (childIndex + 1 < length && array[childIndex] < array[childIndex + 1]) {
			childIndex++;
		}
		//if (array[parentIndex] > array[childIndex])   //错误在这里！！！  应该是temp >= array[childIndex]
		if(temp >= array[childIndex])
			break;
		array[parentIndex] = array[childIndex];
		parentIndex = childIndex;
		childIndex = 2 * childIndex + 1;
	}
	array[parentIndex] = temp;
}

void heapSort(vector<int> &array) {
	//先把无序堆构建成最大堆
	//int size = sizeof(array) / sizeof(*array);
	int size = 10;
	for (int i = (size - 2)/2; i >= 0; i--) {
		downAdjust(array, i, size);
		//cout << array[i]+" ";
	}
	
	//把最大堆的对顶元素删除（不是完全删除，只是放到堆尾）
	for (int i = (size - 1); i > 0; i--) {
		int temp = array[i];
		array[i] = array[0];
		array[0] = temp;
		//下沉 调整最大堆
		downAdjust(array, 0, i);
	}
}


int main() {
	vector<int> array = { 1,3,2,6,5,7,8,9,10,0 };
	heapSort(array);

	for (int i = 0; i < 10; i++)
		cout << array[i];
	
	system("pause");
	return 0;
}