def judgePoint24(items):
    if len(items) == 1:
        return items[0] == 24 or abs(items[0] - 24.0) <= 0.1
    for i in range(len(items)):
        for j in range(len(items)):
            if i == j:
                continue
            indexes = set([x for x in range(len(items))])
            indexes.remove(i)
            indexes.remove(j)
            r = []
            r.append(float(items[i]) + float(items[j]))
            r.append(float(items[i]) - float(items[j]))
            r.append(float(items[j]) - float(items[i]))
            r.append(float(items[i]) * float(items[j]))
            if items[j] != 0:
                r.append(float(items[i]/float(items[j])))
            if items[i] != 0:
                r.append(float(items[j]/float(items[i])))
            next_items = [items[idx] for idx in indexes]
            for x in r:
                if judgePoint24(next_items + [x]) == True:
                    return True
    return False
