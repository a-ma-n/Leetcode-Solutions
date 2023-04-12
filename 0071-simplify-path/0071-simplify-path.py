class Solution:
    def simplifyPath(self, path: str) -> str:

        stack = []

        for portion in path.split("/"):
            if portion == "..":
                if stack:
                    stack.pop()
            elif portion == "." or not portion:
                # A no-op for a "." or an empty string
                continue
            else:
                stack.append(portion)

        return "/" + "/".join(stack)