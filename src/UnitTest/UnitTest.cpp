#include "pch.h"
#include "CppUnitTest.h"

#include "../include/lib_func.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(初期化)
	{
	public:

		TEST_METHOD(リストの初期化)
		{
			list lst;
			initialize_list(&lst);

			Assert::IsNull(lst.header);
		}

		TEST_METHOD(ノードの初期化)
		{
			node n;
			initialize_node(&n, 1);

			Assert::IsNull(n.pNext);
			Assert::AreEqual(1, n.data);
		}
	};

	TEST_CLASS(要素の取得)
	{
	public:

		TEST_METHOD(NULLの次はNULL)
		{
			list lst;
			initialize_list(&lst);

			Assert::IsNull(get_next(NULL));
		}
	};

	TEST_CLASS(追加)
	{
	public:

		TEST_METHOD(一番前に追加（一要素）)
		{
			list lst;
			initialize_list(&lst);

			node n;
			initialize_node(&n, 12);

			push_front(&lst, &n);

			node* p = lst.header;
			Assert::AreEqual((void*)&n, (void*)p);
			Assert::AreEqual(p->data, 12);
			Assert::IsNull(get_next(p));
		}

		TEST_METHOD(一番前に追加（三要素）)
		{
			list lst;
			initialize_list(&lst);

			node n0, n1, n2;
			initialize_node(&n0, 124);
			initialize_node(&n1, 125);
			initialize_node(&n2, 126);

			push_front(&lst, &n0);
			push_front(&lst, &n1);
			push_front(&lst, &n2);

			node* p = lst.header;
			Assert::AreEqual((void*)&n2, (void*)p);
			Assert::AreEqual(p->data, 126);
			p = get_next(p);
			Assert::AreEqual((void*)&n1, (void*)p);
			Assert::AreEqual(p->data, 125);
			p = get_next(p);
			Assert::AreEqual((void*)&n0, (void*)p);
			Assert::AreEqual(p->data, 124);
			Assert::IsNull(get_next(p));
		}
	};

	TEST_CLASS(次の要素を削除)
	{
	public:
		TEST_METHOD(二つの要素で二つ目の要素を削除)
		{
			list lst;
			initialize_list(&lst);

			node n0, n1;
			initialize_node(&n0, 1234);
			initialize_node(&n1, 1235);

			push_front(&lst, &n1);
			push_front(&lst, &n0);

			remove_next(&lst, &n0);

			node* p = lst.header;
			Assert::AreEqual((void*)&n0, (void*)p);
			Assert::AreEqual(p->data, 1234);
			Assert::IsNull(get_next(p));
		}

		TEST_METHOD(三つの要素の中央を削除)
		{
			list lst;
			initialize_list(&lst);

			node n0, n1, n2;
			initialize_node(&n0, 1245);
			initialize_node(&n1, 1246);
			initialize_node(&n2, 1247);

			push_front(&lst, &n2);
			push_front(&lst, &n1);
			push_front(&lst, &n0);

			remove_next(&lst, lst.header);

			node* p = lst.header;
			Assert::AreEqual((void*)&n0, (void*)p);
			Assert::AreEqual(p->data, 1245);
			p = get_next(p);
			Assert::AreEqual((void*)&n2, (void*)p);
			Assert::AreEqual(p->data, 1247);
			Assert::IsNull(get_next(p));
		}

		TEST_METHOD(三つの要素の末尾を削除)
		{
			list lst;
			initialize_list(&lst);

			node n0, n1, n2;
			initialize_node(&n0, 1255);
			initialize_node(&n1, 1256);
			initialize_node(&n2, 1257);

			push_front(&lst, &n2);
			push_front(&lst, &n1);
			push_front(&lst, &n0);

			remove_next(&lst, &n1);

			node* p = lst.header;
			Assert::AreEqual((void*)&n0, (void*)p);
			Assert::AreEqual(p->data, 1255);
			p = get_next(p);
			Assert::AreEqual((void*)&n1, (void*)p);
			Assert::AreEqual(p->data, 1256);
			Assert::IsNull(get_next(p));
		}

		TEST_METHOD(三つの要素の末尾の後ろを削除しようとする)
		{
			list lst;
			initialize_list(&lst);

			node n0, n1, n2;
			initialize_node(&n0, 1265);
			initialize_node(&n1, 1266);
			initialize_node(&n2, 1267);

			push_front(&lst, &n2);
			push_front(&lst, &n1);
			push_front(&lst, &n0);

			remove_next(&lst, &n2);

			// 変更がないべき
			node* p = lst.header;
			Assert::AreEqual((void*)&n0, (void*)p);
			Assert::AreEqual(p->data, 1265);
			p = get_next(p);
			Assert::AreEqual((void*)&n1, (void*)p);
			Assert::AreEqual(p->data, 1266);
			p = get_next(p);
			Assert::AreEqual((void*)&n2, (void*)p);
			Assert::AreEqual(p->data, 1267);
			Assert::IsNull(get_next(p));
		}

		TEST_METHOD(三つの要素の二つを削除)
		{
			list lst;
			initialize_list(&lst);

			node n0, n1, n2;
			initialize_node(&n0, 1275);
			initialize_node(&n1, 1276);
			initialize_node(&n2, 1277);

			push_front(&lst, &n2);
			push_front(&lst, &n1);
			push_front(&lst, &n0);

			remove_next(&lst, lst.header);
			remove_next(&lst, lst.header);

			node* p = lst.header;
			Assert::AreEqual((void*)&n0, (void*)p);
			Assert::AreEqual(p->data, 1275);
			Assert::IsNull(get_next(p));
		}
	};
}
