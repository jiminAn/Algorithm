# 우선순위가 낮은 기호를 기준으로 split()
def calc(priority, n, expression):
    if n == 2: # 마지막 인덱스일 경우 기호 상관없이 eval()에서 연산 수행하면 됨
        return str(eval(expression))
    if priority[n] == '*':
        res = eval('*'.join([calc(priority, n+1, e) for e in expression.split('*')]))
    if priority[n] == '+':
        res = eval('+'.join([calc(priority, n+1, e) for e in expression.split('+')]))
    if priority[n] == '-':
        res = eval('-'.join([calc(priority, n+1, e) for e in expression.split('-')]))
    return str(res)

def solution(expression):
    answer = 0
    priorities = [ # 우선순위가 낮은 순으로 [0] < [1] < [2] 리스트 저장
        ('*', '-', '+'),
        ('*', '+', '-'),
        ('+', '*', '-'),
        ('+', '-', '*'),
        ('-', '*', '+'),
        ('-', '+', '*')
    ]
    for priority in priorities:
        res = int(calc(priority, 0, expression))
        answer = max(answer, abs(res))
    
    return answer
