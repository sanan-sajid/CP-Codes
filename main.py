import requests
import json
import time

def get_solved_problems(handle):

    url = f"https://codeforces.com/api/user.status?handle={handle}"
    solved_set = set()

    try:
        # Make the API request
        response = requests.get(url, timeout=10)
        response.raise_for_status()  # Raise an exception for HTTP errors (like 404, 500)
        data = response.json()
    except requests.exceptions.RequestException as e:
        print(f"❌ Network Error for handle '{handle}': {e}")
        return None

    # Check if the API call was successful
    if data.get('status') != 'OK':
        print(f"❌ API Error for handle '{handle}': {data.get('comment', 'Unknown error')}")
        return None

    # Iterate through all submissions
    for submission in data.get('result', []):
        # We only care about submissions that are accepted ('OK')
        if submission.get('verdict') == 'OK' and 'problem' in submission:
            problem_info = submission['problem']
            # Ensure the problem has a contestId and index (regular contest problems)
            if 'contestId' in problem_info and 'index' in problem_info:
                problem_id = f"{problem_info['contestId']}{problem_info['index']}"
                solved_set.add(problem_id)
                
    return solved_set

def process_handles_and_problems(handles, problems_to_check):
    """
    For each handle, checks how many problems from the given list they have solved.
    """
    # Convert the list of problems to a set for efficient checking
    problems_set = set(problems_to_check)
    print(f"Checking {len(handles)} handles against {len(problems_set)} unique problem(s)...\n")

    for handle in handles:
        print(f"Processing handle: {handle}...")
        user_solved_set = get_solved_problems(handle)

        # If getting data failed, user_solved_set will be None.
        if user_solved_set is None:
            # The error was already printed, so just add a separator and move on.
            print("-" * 30)
            time.sleep(1) # Wait a bit before the next request
            continue

        # Find the common problems between what the user solved and our list
        solved_from_list = user_solved_set.intersection(problems_set)
        solved_count = len(solved_from_list)

        print(f"✅ Result: {handle} has solved {solved_count} problem(s) from the list.")
        if solved_count > 0:
            # Print which specific problems they solved from the list
            print(f"   -> Solved: {', '.join(sorted(list(solved_from_list)))}")
        print("-" * 30)
        
        # A 1-second delay is polite to the Codeforces API
        time.sleep(1)

if __name__ == "__main__":
    # The JSON now contains a simple list of handles (usernames), not full URLs.
    handles_json = """
    [
        "fluxrated",
        "tourist"
    ]
    """
    
    # The list of problems to check for.
    problems_json = """
    [
        "1999B",
        "1985H1"
    ]
    """
    
    try:
        # Load the JSON data into Python lists
        handles = json.loads(handles_json)
        problems = json.loads(problems_json)
    except json.JSONDecodeError as e:
        print(f"Error: Invalid JSON format. Please check your input. Details: {e}")
        exit() # Stop the script if JSON is malformed
    
    # Run the main processing function
    process_handles_and_problems(handles, problems)