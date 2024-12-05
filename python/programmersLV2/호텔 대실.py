import heapq


def change_min(str_time: str):
    return int(str_time[:2]) * 60 + int(str_time[3:])


def solution(book_time):
    book_times = [[change_min(start), change_min(end) + 10] for start, end in book_time]

    book_times.sort()

    pq = []

    for start, end in book_times:
        if pq and pq[0] <= start:
            heapq.heappop(pq)
        heapq.heappush(pq, end)

    return len(pq)

print(solution([["15:00", "17:00"], ["16:40", "18:20"], ["14:20", "15:20"], ["14:10", "19:20"], ["18:20", "21:20"]]))