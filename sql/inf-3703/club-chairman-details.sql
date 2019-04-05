SELECT member.*, contact_details.*, address.*
	FROM CLUB club
	INNER JOIN MEMBER member
	ON member.MEMBER_CODE = club.CLUB_CHAIRMAN_MEMCODE
	AND club.CLUB_CODE = @club_code
	INNER JOIN CONTACT_DETAILS contact_details
	ON contact_details.CONTACT_CODE = member.CONTACT_CODE
	INNER JOIN ADDRESS address
	ON address.ADDRESS_CODE = member.ADDRESS_CODE;