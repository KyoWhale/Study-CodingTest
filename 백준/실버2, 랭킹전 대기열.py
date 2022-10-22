# 14:23 ~ 14:37

p, m = map(int, input().split())
players = [input() for _ in range(p)]

rooms = []
def try_join(m, rooms, level, name):
    for i in range(len(rooms)):
        room = rooms[i]
        if len(room) == m:
            continue

        if room[0][0]-10 <= level <= room[0][0]+10:
            room.append((level,name))
            return True

    return False

for player in players:
    level, name = player.split()
    level = int(level)

    if rooms:
        result = try_join(m, rooms, level, name)
        if result == False:
            rooms.append([(level, name)])
    else:
        rooms.append([(level, name)])

for room in rooms:
    room = sorted(room, key=lambda x : (x[1], x[0]))

    if len(room) == m:
        print("Started!")
        for j in range(len(room)):
            print(room[j][0], room[j][1])
    else:
        print("Waiting!")
        for j in range(len(room)):
            print(room[j][0], room[j][1])