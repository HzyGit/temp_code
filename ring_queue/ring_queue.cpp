#include "ring_queue.h"

#ifdef GTEST_TEST
#include <gtest/gtest.h>
TEST(TestRingQueue,TestConstruct)
{
	RingQueue<int> b;
	ASSERT_EQ(1024,b.capacity());
	ASSERT_EQ(0,b.size());
	ASSERT_TRUE(b.empty());
	ASSERT_FALSE(b.full());

	RingQueue<int> a(3);
	ASSERT_EQ(3,a.capacity());
	ASSERT_EQ(0,a.size());
	ASSERT_FALSE(a.full());
	ASSERT_TRUE(a.empty());

	RingQueue<int> c(0);
	ASSERT_EQ(0,c.capacity());
	ASSERT_EQ(0,c.size());
	ASSERT_TRUE(c.empty());
	ASSERT_TRUE(c.full());

}

TEST(TestRingQueue,TestClear)
{
	RingQueue<int> c(1);
	c.clear();
	ASSERT_EQ(0,c.size());
	ASSERT_TRUE(c.empty());
}

TEST(TestRingQueue,TestPush)
{
	RingQueue<int> q(3);
	q.push(1);
	ASSERT_EQ(1,q.size());
	q.push(2);
	q.push(3);
	ASSERT_TRUE(q.full());
	ASSERT_FALSE(q.push(4));
}

TEST(TestRingQueue,TestPushPop)
{
	RingQueue<int> q(3);
	for(int i=0;i<q.capacity();i++)
		q.push(i);
	for(int i=0;i<3;i++)
	{
		ASSERT_EQ(i,q.front());
		ASSERT_TRUE(q.pop());
	}
	ASSERT_FALSE(q.pop());
	ASSERT_TRUE(q.empty());
}

#endif
