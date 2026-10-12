import sys


class IntegerError(Exception):
    pass


def input_arg(temp_str: str) -> int:
    try:
        return int(temp_str)
    except ValueError:
        raise IntegerError(f"Invalid parameter: {temp_str}")


def error() -> str:
    return (f"No scores provided. Usage: python3 {sys.argv[0]} <score1> "
            f"<score2> ...")


def ft_score_analytics() -> None:
    scores = []
    for arg in sys.argv[1:]:
        try:
            scores.append(input_arg(arg))
        except IntegerError as e:
            print(e)
    if not scores:
        print(error())
        return
    print(f"Scores processed: {scores}")
    print(f"Total players: {len(scores)}")
    print(f"Total score: {sum(scores)}")
    print(f"Average score: {sum(scores) / len(scores)}")
    print(f"High score: {max(scores)}")
    print(f"Low score: {min(scores)}")
    print(f"Score range: {max(scores) - min(scores)}")


if __name__ == "__main__":
    print("=== Player Score Analytics ===")
    ft_score_analytics()
