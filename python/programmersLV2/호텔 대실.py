import heapq
def make_int(book_time):
    return int(book_time[0:2]) * 100 + int(book_time[3:5])


def solution(book_time):
    answer = 0
    int_book_time = []
    for i in range(0, len(book_time)):
        start_time = make_int(book_time[i][0])
        end_time = make_int(book_time[i][1])
        int_book_time.append([start_time, end_time])
    int_book_time = sorted(int_book_time, reverse=True)

    int_book_time.sort()

    pq = []
    for start, end in int_book_time:
        if(len(pq) != 0 and pq[0] <= start ) :
            heapq.heappop(pq)
        heapq.heappush(pq, end)
    return len(pq)


print(solution([["15:00", "17:00"], ["16:40", "18:20"], ["14:20", "15:20"], ["14:10", "19:20"], ["18:20", "21:20"]]))