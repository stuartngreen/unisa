SELECT 
	member.MEMBER_FIRST_NAME,
	member.MEMBER_SURNAME,
	member.MEMBER_PRIMARY_CALLSIGN_CODE
	FROM MEMBER member
	INNER JOIN MEMBER_CLUB member_club
	ON member_club.MEMBER_CODE = member.MEMBER_CODE
	AND member_club.CLUB_CODE = @club_code;