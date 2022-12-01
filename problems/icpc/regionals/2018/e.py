def main():
    message = input()
    crib = input()
    ans, message_length, crib_length = 0, len(message), len(crib)
    for i in range(message_length - crib_length + 1):
        for j in range(crib_length):
            if crib[j] == message[i + j]:
                break
        else:
            ans += 1
    print(ans)
main()
