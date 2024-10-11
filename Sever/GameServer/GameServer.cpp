#include "pch.h"

#include "AccountManager.h"
#include "UserManager.h"

// Lock based Stack
// Lock based Queue
#include "LockBasedQueue.h"
#include "LockBasedStack.h"

#include "ThreadManager.h"
#include "Lock.h"
#include "RefCounting.h"

// window
// linux
//
#pragma region 두번쨰_아토믹
//atomic<int32> sum = 0; // all or notting
//
//void AddSum()
//{
//    for (int i = 0; i < 100000; i++)
//    {
//        sum.fetch_add(1);
//        
//    }
//}
//
//void SubSum()
//{
//    for (int i = 0; i < 100000; i++)
//    {
//        sum.fetch_sub(1);
//    }
//}
#pragma endregion

#pragma region 시작부
//void HelloThread()
//{
//    cout << "Hello World" << endl;
//}
//
//void HelloThread_One(int number)
//{
//    cout << number << endl;
//}
#pragma endregion

#pragma region 세번째

//std::mutex m; // 자물쇠 역할
//vector<int> v;
//// mutual exclusive : 상호 배제
//// -> lock
//
//template<typename T>
//class LockGuard
//{
//public:
//    LockGuard(T* mutex) : _mutex(mutex) { _mutex->lock(); }
//    ~LockGuard() { _mutex->unlock(); }
//
//private:
//    T* _mutex;
//};
//
//void Push(int count)
//{
//    //m.lock();
//    LockGuard<std::mutex> lockguard(&m);
//
//    for (int i = 0; i < count; i++)
//    {
//        // 이중 락
//        v.push_back(1);
//    }
//    
//    //m.unlock();
//    return;
//}

#pragma endregion

#pragma region 네번째
//void Func1()
//{
//    for (int32 i = 0; i < 10000; i++)
//    {
//        UserManager::GetInstance()->Save();
//    }
//}
//void Func2()
//{
//    for (int32 i = 0; i < 10000; i++)
//    {
//        AccountManager::GetInstance()->LogIn();
//    }
//}

#pragma endregion

#pragma region 다섯쨰


// Spin Lock 

//class SpinLock
//{
//public:
//    SpinLock() {}
//    ~SpinLock() {}
//
//    void lock()
//    {
//        // 둘이 경합이 동시에 일어났다.
//        
//        // check 하고 setting 하는 작업이 원자적으로 처리되어야한다.
//        // => Compare And Swap (CAS)
//       
//        bool expected = false; // flag 의 예상값은 false
//        bool desired = true; // flag 가 ture 였으면 좋겠다.
//
//        // compare_exchange_strong
//        //if (flag == expected) // 
//        //{
//        //    expected = flag;
//        //    flag = desired;
//        //    return true;
//        //}
//        //else // flag 가 desired 와 같다.
//        //{
//        //    expected = flag;
//        //    return false;
//        //}
//
//        while(flag.compare_exchange_strong(expected, desired) == false)
//        { 
//            expected = false;
//
//            this_thread::sleep_for(std::chrono::seconds(0));
//            //this_thread::yield();
//        }
//    }
//    void unlock()
//    {
//        flag = false;
//    }
//private:
//    atomic<bool> flag = false;
//};
//
//int32 sum = 0;
//SpinLock myLock;
//
//void Add()
//{
//    for (int32 i = 0; i < 100'0000; i++)
//    {
//        // lock...flag = false
//        std::lock_guard<SpinLock> lg(myLock);
//        // lock... flag = true
//        sum++;
//    }
//}
//void Sub() {
//    for (int32 i = 0; i < 100'0000; i++)
//    {
//        // lock... flag = true
//        std::lock_guard<SpinLock> lg(myLock);
//        sum--;
//    }
//}

#pragma endregion

#pragma region 여섯쨰
//queue<int32> q;
//mutex m;
////HANDLE handle;
//condition_variable cv;
//
//void Producer()
//{
//    while (true)
//    {
//        //1. Lock 을 잡고
//        // 2. 공유 변수 값을 추정 ( q.push(100))
//        // 3. Lock 를 풀고 
//        // 4. 조건변수를 통해 다른 쓰레드에게 통지
//
//        {
//            unique_lock<std::mutex> lock(m); // 1
//            q.push(100); // 2
//        }// 3
//
//        // wait 중인 Thread가 있으면 딱 1개를 꺠운다.
//        cv.notify_one(); // 4
//
//
//        //::SetEvent(handle);
//
//       // this_thread::sleep_for(10000ms);
//
//    }
//}
//
//void Consumer()
//{
//    while (true)
//    {
//        //::WaitForSingleObject(handle, INFINITE);
//
//        // P_A_C : Consumer
//        // 1. Lock 를 잡고
//        // 2. 조건확인
//        // - 만족했다 => 이어서 코드진행
//        // - 불만족 => 'Lock을 풀어주고' 대기상태
//
//        unique_lock<std::mutex> lock(m); // 1
//
//        cv.wait(lock, []()->bool {return q.empty() == false; }); // 2
//
//        //if (q.empty() == false)
//        {
//            int32 data = q.front();
//
//            q.pop();
//            //cout << data << endl;
//            cout << q.size() << endl;
//        }
//    }
//}

#pragma endregion

#pragma region 일곱째
// Lock 구현
// 1. Spin Lock( BUsy Waiting )
// 2. Sleep 기반 Lock
// 3. Event 기반 Lock

// 3... Linux에서도,,?
// => cv( condition_variable )
// .... 조건을 걸고 조건이 참일 떄만 락을 걸어잠그고 실행
// => 멀티쓰레드 환경에서 Sleep을 시키지 않으면 올바르게 동작하지 않을 수도 있다.
// .... 동시성이 생길때 Produce를 더할 수도 있다.

// 디자인 패턴
// Produce And Consumer 패턴... Queue
// 

//int64  Caculate()
//{
//    int64 sum = 0;
//
//    for(int i = 0; i < 100'0000; i++)
//    {
//        sum++;
//    }
//
//    for (int i = 0; i < 10; i++)
//    {
//        int temp = 0; // 동기로 실행 됬을 떄는 temp가 먼저 잡히고
//                       // 비동기로 실행됬을 떄는 예측할수 없다.
//    }
//
//    return sum;
//}
//
//void PromiseWorker(std::promise<string>&& promise)
//{
//    promise.set_value("Set Message");
//
//}
//
//void TaskWorker(std::packaged_task<int64(void)>&& task)
//{
//    task();
//}

#pragma endregion

#pragma region 여덟쨰
// 캐시
// - CPU에 있는 임시 저장공간
// - 코어 마다 있다. (L1, L2), 아닌것도 있다(L3)
//  
// - 캐시 철학
// -- Temporal Locality : 시간적 지역 -> "방금"본 메모리에서 또 다시 접근할 일이 생길 거 같다.
// -- Spatial Loclaity : 공간적 지역 -> 봤던 메모리 '주변'에 또 접근할 일이 생길거 같다.
// => 메모리 탐색을 최소화 시키려는 전략

//int32 buffer[10000][10000];


#pragma endregion

#pragma region 아홉쨰
//// CPU PipeLine
//int32 x;
//int32 y;
//int32 result1;
//int32 result2;
//
//volatile bool ready;
//
//// 1. 실제 메모리에 정말 x, y 가 1 이라고 되어있을까?
//// 코어 마다 cache가 있다.
//// 멀티쓰레드환경에서만 발생할수 있는 문제
//// => 캐쉬를 통해서 메모리에 접근해서 값을 넣기 전에 동시에 실행됬다면?
//
//// ---> 가시성 문제
//
//// 2. CPU 파이프라인 
//// - fetch          : 읽기
//// - Decode         : 해석
//// - Excute         : 실행
//// - Memory Access  : 메모리접근(쓰기)
//// 일감을 병렬로 처리하기 위해서 큰 작업부터 시행한다.
//
//// ---> 코드 재배치
//
//void Thread_1()
//{
//    while (ready)
//    ;
//
//    result1 = x; // x의 값을 가져와서 대입하는게 좀더 시간이 걸리는 작업
//    y = 1;
//}
//
//void Thread_2()
//{
//    while (ready)
//    ;
//
//    result2 = y;
//    x = 1;
//}

#pragma endregion

#pragma region 열번쨰_메모리정책
  // 메모리 모델
// 1. 여러 쓰레드가 동일한 메모리(공용 변수)에 동시에 접근, 쓰기(write)할 때 생기는 문제들 파악
// 2. 이때 경합조건(Rece Condition) 
// 3. Race Condition 을 어떻게 막을 것이냐
//  ... Undefined Behavior(정의되지 않은 행동)
// => atomic
// => Lock(mutex) ,,, Mutual Exclusion(상호 베타)

// 우리의 메모리 정책
// 1. atomic을 이용해서 코드 재배치를 막고, 가시성을 지킨다.

// atomic 연산에 한해, 모든 쓰레드가 동일 객체에 대해서 동일한 수정 순서를 관찰.
// =>가시성

// atomic... 메모리정책
// => 코드 재배치



#pragma endregion

#pragma region 열한번쨰_메모리정책_atomic
//atomic<int32> flag;
//int32 value;
//
//void Producer()
//{
//    value = 10;
//
//
//    flag.store(1, memory_order_release); // seq_cst ... 이 위로 모든 값들이 보정
//}
//
//void Consumer()
//{
//    while(flag.load(memory_order_acquire) != 1)
//    {
//
//    }
//
//
//    cout << value << endl;
//}

#pragma endregion

#pragma region 열두번쨰_TLS
// TLS 영역이란..
// 각 쓰레드마다 가지고 있는 고유 메모리 저장공간

// 거실에 일감이 있다.
// -> 거실에 있는 일감을 4명이서 분배해서 일을 하고 싶다.
// -> 4명이서 거실에 다같이 일을 하려고 한다.
// -> 일감을 조금씩 떼어서 각자 자기방에 들어가서 일을 해놓고
//    다시 거실에 갓다 놓는다면?

// TLS (Thread Local Storage)
//
//thread_local int32 L_threadId; // TLS 영역
//
//void MySetThreadId(int32 id)
//{
//    L_threadId = id;
//
//    while (true)
//    {
//        cout << "Hi Im thread :" << L_threadId << endl;
//        this_thread::sleep_for(1000ms);
//    }
//}

#pragma endregion

#pragma region 열세번쨰_Lock Based Stack / Queue
// Lock Based Stack
// Lock Based Queue
//LockBasedStack<int32> s;
//LockBasedQueue<int32> q;
//
//void Push()
//{
//    while (true)
//    {
//        int32 value = rand() % 100;
//        q.Push(value);
//
//        this_thread::sleep_for(100ms);
//    }
//}
//
//void Pop()
//{
//    while (true)
//    {
//        int32 data = 0;
//
//        //s.WaitPop(data);
//
//        if (q.TryPop(data))
//        {
//            cout << data << endl;
//        }
//    }
//}

#pragma endregion

#pragma region 열네번쨰
//class TestJob
//{
//    USE_LOCK;
//
//public:
//    int TestRead()
//    {
//        READ_LOCK;
//
//        if (q.empty() == false)
//            return q.front();
//    }
//
//    void TestPush()
//    {
//        WRITE_LOCK;
//
//        q.push(rand() % 100);
//    }
//
//    void TestPop()
//    {
//        WRITE_LOCK;
//
//        if (q.empty() == false)
//        {
//            q.pop();
//        }
//    }
//
//private:
//    queue<int> q;
//    Lock _lock;
//
//};
//
//TestJob GJob;
//void ThreadRead()
//{
//    while (true)
//    {
//        int num = GJob.TestRead();
//        cout << num << endl;
//    }
//}
//
//void ThreadWrite()
//{
//    while (true)
//    {
//        GJob.TestPush();
//        this_thread::sleep_for(100ms);
//        GJob.TestPop();
//    }
//}
#pragma endregion

#pragma region 열다섯번쨰

//const int MAX_NUMBER = 100'0000;
//
//bool IsPrime(int num)
//{
//    if (num == 0 || num == 1) return false;
//    if (num == 2 || num == 3) return true;
//
//    int findNum = (int)sqrtf(num);
//
//    for (int i = 2; i <= findNum; i++)
//    {
//        if (num % i == 0)
//            return false;
//    }
//
//    return true;
//}
//
//atomic<int> result = 0;
//void PrimeRange(int start , int end)
//{
//    // primeNum이면 result를 올린다.
//    for (int i = start; i < end; i++)
//    {
//        if (IsPrime(i))
//            result.fetch_add(1);
//    }
//
//}
//
//int solution()
//{
//    vector<thread> threads;
//
//    int coreCount = thread::hardware_concurrency();
//    int temp = MAX_NUMBER / coreCount;
//
//    for (int i = 0; i < coreCount; i++)
//    {
//        //oh(i + (a * i), a * (i + 1));
//        int start = temp * i;
//        int end = temp * (i + 1);
//        if (end > MAX_NUMBER || i == coreCount - 1) end = MAX_NUMBER;
//
//        threads.push_back(thread(PrimeRange, start, end));
//    }
//
//    for (auto& thread : threads)
//    {
//        thread.join();
//    }
//    return result;
//
//    //int count = 0;
//    //for (int i = 2; i < MAX_NUMBER; i++)
//    //{
//    //    if (IsPrime(i))
//    //        count++;
//    //}
//
//    //return count;
//}

#pragma endregion

#pragma region 열여섯번쨰
//void Login()
//{
//    while (true)
//        AccountManager::GetInstance()->Login();
//}
//
//void Save()
//{
//    while (true)
//        UserManager::GetInstance()->Save();
//}


#pragma endregion

#pragma region 열일곱번쨰
using PlayerRef = TSharedPtr<class Player>;

class Player : public RefCountable
{
public:
    ~Player() 
    {
    
    }

    void Attack()
    {
        if (_target != nullptr)
        {
            _target->_hp -= _atk;
        }
    }

    bool IsDead()
    {
        return _hp <= 0;
    }

public:
    PlayerRef _target;

    int _hp;
    int _atk;
};


#pragma endregion

#pragma region 열여덟번쨰

#pragma endregion
int main()
{
#pragma region 열여덟번쨰

#pragma endregion

#pragma region 열일곱번쨰
    CoreGlobal::Create();

    PlayerRef p1 = new Player();
    p1->ReleaseRef();
    p1->_hp = 10000;
    p1->_atk = 15;

    PlayerRef p2 = new Player();
    p2->ReleaseRef();
    p2->_hp = 20000;
    p2->_atk = 15;

    // shared ptr 의 순환참조 문제
    p2->_target = p1;
    //p1->_target = p2;

    TSharedPtr<Player> p3 = TSharedPtr<Player>(new Player());

    while (true)
    {
        if (p1 != nullptr)
        {
            p2->Attack();

            if (p2->IsDead())
            {
                p1 = nullptr;
                break;
            }
        }
    }

    CoreGlobal::Delete();

    return 0;
#pragma endregion

#pragma region 열여섯번쨰

    //CoreGlobal::Create();

    //AccountManager::Create();
    //UserManager::Create();


    //// DeadLock
    //TM_M->Launch(Login);
    //TM_M->Launch(Save);

    //TM_M->Join();


    //AccountManager::Delete();
    //UserManager::Delete();

    //CoreGlobal::Delete();

    //return 0;

#pragma endregion

#pragma region 열다섯번쨰
    /*CoreGlobal::Create();

    int64 start = ::GetTickCount64();

    int answer = 0;

    answer = solution();

    cout << answer << endl;

    int64 end = ::GetTickCount64();

    cout << " 걸린시간 : " << end - start << "ms" << endl;

    CoreGlobal::Delete();

    return 0;*/

#pragma endregion

#pragma region 열네번쨰
    /*CoreGlobal::Create();

    for (int i = 0; i < 2; i++)
    CoreGlobal::Instance()->TM()->Launch(ThreadWrite);

    for (int i = 0; i < 5; i++)
    CoreGlobal::Instance()->TM()->Launch(ThreadRead);


    CoreGlobal::Delete();

    return 0;*/

#pragma endregion

#pragma region 열세번쨰_Lock Based Stack / Queue

    //thread t1(Push);
    //thread t2(Pop);
    //thread t3(Pop);

    //int aInt = 10;

    //if (aInt != 10)
    //    CRASH("aInt is not 10");
    ////ASSERT_CRASH(aInt == 10);

    //t1.join();
    //t2.join();
    //t3.join();

  /*  CoreGlobal::Create();

    CoreGlobal::Instance()->TM()->Launch(&Push);
    CoreGlobal::Instance()->TM()->Launch(&Pop);
    CoreGlobal::Instance()->TM()->Launch(&Pop);

    CoreGlobal::Delete();*/

    //return 0;
#pragma endregion

#pragma region 열두번쨰_TLS
    /*vector<thread> threads;

    for (int i = 0; i < 10; i++)
    {
        threads.push_back(thread(MySetThreadId,(i + 1)));
    }

    for (auto& t : threads)
    {
        t.join();
    }

    return 0;*/
#pragma endregion

#pragma region 열한번쨰_메모리정책_atomic
    //flag.store(0); 
    //value = 0;

    //thread t1(Producer);
    //thread t2(Consumer);

    //t1.join();
    //t2.join();


    //// Memory 정책
    //// 1. seq_cst( sequential consistency ) // 순서적 일관성 => 매우 엄격
    //// - 코드 재배치x, 가시성o
    //// 
    //// 2. acquire - release => 중도
    //// 3. relaxed => 컴파일러 최적화 여지가 많다.



    //return 0;
#pragma endregion

#pragma region 열번쨰_메모리정책
    //atomic<bool> flag = false;
    //
    //// atomic 변수 flag에 값을 저장
    //flag.store(true, memory_order::memory_order_seq_cst);

    //// atomic 변수를 읽어오는 것 => 읽기
    //bool val = flag.load(memory_order::memory_order_seq_cst);

    //// prev에다 flag의 바꾸기 전 값을 넣고, flag를 수정
    //{

    //    bool prev = flag.exchange(true);
    //}

    //// 조건부 수정 : condition variable
    //// => cv 라는 객체가 내 예상이 맞으면 바꿔주고, 아니면 말고
    //{
    //    bool expected = false; // 내 예상은 이게 false일 것이다.
    //    bool desired = true; // 내 예상이 맞으면 desired로 바꿔줘

    //    flag.compare_exchange_strong(expected, desired);
    //    //flag.compare_exchange_weak(expected, desired); =>while(true)
    //}


    //return 0;
#pragma endregion

#pragma region 아홉쨰
   /* int32 count = 0;

    while (true)
    {
        ready = true;
        count++;

        x = y = result1 = result2 = 0;

        thread t1(Thread_1);
        thread t2(Thread_2);

        ready = false;

        t1.join();
        t2.join();

        if (result1 == 0 && result2 == 0) break;

    }

    cout << count << " 번 만에 탈출 성공!!!" << endl;*/

#pragma endregion

#pragma region 여덟쨰
    /*memset(buffer, 0, sizeof(buffer));

    {
        uint32 start = GetTickCount64();

        int64 sum = 0;
        for (int32 i = 0; i < 10000; i++)
        {
            for (int32 j = 0; j < 10000; j++)
            {
                sum += buffer[i][j];
            }
        }

        uint32 end = GetTickCount64();

        cout << "Elipsed Time : " << end - start << endl;
    }

    {
        uint32 start = GetTickCount64();

        int64 sum = 0;
        for (int32 i = 0; i < 10000; i++)
        {
            for (int32 j = 0; j < 10000; j++)
            {
                sum += buffer[j][i];
            }
        }

        uint32 end = GetTickCount64();

        cout << "Elipsed Time : " << end - start << endl;

    }

    return 0;*/
#pragma endregion

#pragma region 일곱쨰

    //// 동기방지 ( synchrinous )
    ////int64 sum = Caculate();

    //// future : 미래
    //{
    //    // 비동기바익(asynchronous)
    //    // std::launch::deferred => 지연해서 실행시켜주세요
    //    // std::launch::async => 쓰레드를 하나 따로 만들어서 실행
    //    std::future<int64> future = std::async(std::launch::async, Caculate);

    //    // TODO... => furure 가 끝나던지 끝나지 않던지 간에 이 내용들이 실행
    //    int t = 1;

    //    int64 sum = future.get(); // get : 힘수가 끝날 때 까지 기달려서 리턴값

    //    cout << sum << endl;
    //}

    //// Promise : 
    //// 미래(future)에 결과물을 반환할 것이라는 약속(promise)을 해줘 -> 계약서
    //{
    //    std::promise<string> promise;
    //    std::future<string> future = promise.get_future(); // future 에 반환하겠다는 약속

    //    thread t(PromiseWorker, std::move(promise)); // promise한테 일 시키기

    //    //future.wait(); // future 가 잘 세팅되어있는지 확인.. 끝날 때까지 대기
    //    std::future_status status = future.wait_for(10ms); // 0.01초 동안 대기하면서 future가 끝났는지 확인.
    //    if (status == std::future_status::ready)
    //    {
    //        // TODO : future가 세팅이 잘되어있다. => 즉시실행 가능

    //    }

    //    string value = future.get(); // 비동기 방식으로 future에 값이 잘 세팅이 되어있는지 확인하고 반환.

    //    cout << value << endl;

    //    t.join();
    //}

    //// packaged_task : 일감을 만들어서 넘겨주는 방법
    //{
    //    std::packaged_task<int64()> task(Caculate);
    //    std::future<int64> future = task.get_future();

    //    thread t(TaskWorker, std::move(task));

    //    int64 sum = future.get();

    //    cout << sum << endl;

    //    t.join();
    //}

    //// Cacluate 하는데 Event방식, SpinLock 방식처럼 Lock, thread만들고 하는 작업들을 최소화
    //// ... 작은 작업들을 비동기 방식으로 할 떄 자주 쓴다.
    //// => future

    //return 0;
#pragma endregion

#pragma region 여섯쨰
    //                    // 보안속성, 메뉴얼 리셋 관련, 초기상태
    //                    //          Manual : 수동의
    ////handle = ::CreateEvent(NULL, FALSE, FALSE, NULL);

    //std::thread t1(Producer);
    //std::thread t2(Consumer);

    //t1.join();
    //t2.join();

    ////::CloseHandle(handle);

    //return 0;

#pragma endregion

#pragma region 다섯쨰
  /*  std::thread t1(Add);
    std::thread t2(Sub);

    t1.join();
    t2.join();

    cout << sum << endl;*/


#pragma endregion

#pragma region 네번쨰

    /* AccountManager::Create();
     UserManager::Create();

     std::thread t1(Func1);
     std::thread t2(Func2);

     t1.join();
     t2.join();

     cout << "Done" << endl;


     AccountManager::Delete();
     UserManager::Delete();*/
#pragma endregion

#pragma region 세번째
     /*v.reserve(100000);

     vector<std::thread> threads;
     threads.resize(10);

     for (int i = 0; i < 10; i++)
     {
         threads[i] = std::thread(Push, 1000);
     }

     for (int i = 0; i < 10; i++)
     {
         threads[i].join();
     }
     cout << v.size() << endl;*/

#pragma endregion

#pragma region 두번쨰
     //vector<std::thread> threads;
     //threads.resize(10);

     //// 5개의 쓰레드가 AddSum 일감을 각각 갖는다.
     //for (int i = 0; i < 5; i++)
     //{
     //    threads[i] = std::thread(AddSum);
     //}

     //// 5개의 쓰레드가 SubSum 일감을 각각 갖는다.
     //for (int i = 5; i < 10; i++)
     //{
     //    threads[i] = std::thread(SubSum);
     //}

     //for (int i = 0; i < 10; i++)
     //{
     //    if (threads[i].joinable())
     //        threads[i].join();
     //}

     //cout << sum << endl;
#pragma endregion

#pragma region 쓰레드 시작부
    // 쓰레드 생성
    // t는 새로운 쓰레드
    //std::thread t(HelloThread_One, 1);

    //cout << "Hello Main" << endl;
    // thread 멤버함수
    // - join
    // - joinable : 
    // - detach : 쓰레드 분리
    // - hardware_concurrency : 현재 운용가능한 쓰레드 개수
    // - get_id : 쓰레드 아이디
    // t가 끝날때 까지 기다려서 합친다. => thread 종료
    //t.join();
#pragma endregion

}