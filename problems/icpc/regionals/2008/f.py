def main():
    while True:
        n = int(input())
        if n == 0:
            break
        h = list(map(int, input().split()))
        h.extend(h[:2])
        peaks = 0
        for i in range(1, n + 1):
            if (h[i]-h[i-1])*(h[i+1]-h[i]) < 0:
                peaks += 1
        print(peaks)
main()
