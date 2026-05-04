import sys

if __name__ == "__main__":
    print("=== Player Score Analytics ===")

    if len(sys.argv) == 1:
        print("No scores provided. Usage: python3 "
              "ft_score_analytics.py <score1> <score2> ...")
    else:
        score_list = []
        for arg in sys.argv[1:]:
            try:
                score_list.append(int(arg))
            except ValueError:
                print(f"Invalid parameter: '{arg}'")
        if len(score_list) == 0:
            print("No scores provided. Usage: "
                  "python3 ft_score_analytics.py <score1> <score2> ...")
        else:
            print(f"Scores processed: {score_list}")
            print(f"Total players: {len(score_list)}")
            print(f"Total score: {sum(score_list)}")
            print(f"Average score: {sum(score_list) / len(score_list)}")
            print(f"High score: {max(score_list)}")
            print(f"Low score: {min(score_list)}")
            print(f"Score range: {max(score_list) - min(score_list)}")
