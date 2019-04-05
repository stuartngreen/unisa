
START TRANSACTION;

	INSERT INTO MEMBER (
			MEMBER_INITIALS,
			MEMBER_TITLE,
			MEMBER_ID_#,
			MEMBER_FIRST_NAME,
			MEMBER_SURNAME,
			MEMBER_LICENCE_#,
			MEMBER_OCCUPATION,
			MEMBER_PRIMARY_CLUB_CODE,
			MEMBER_PRIMARY_CALLSIGN_CODE,
			CONTACT_CODE,
			ADDRESS_CODE,
			CREDITCARD_CODE
		) VALUES (
			@initials,
			@title,
			@id_number,
			@first_name,
			@surname,
			@licence_number,
			@occupation,
			@primary_club_code,
			@primary_callsign_code,
			NULL,
			NULL,
			NULL
		);
		
	SET @member_code = LAST_INSERT_ID();

	INSERT INTO MEMBER_SUBSCRIPTION (
			MEMBER_CODE,
			MEMSUBTYPE_CODE,
			MEMSUB_ACTIVATION_DATE,
			MEMSUB_EXIPRY_DATE,
			MEMSUB_STATUS,
			MEMSUB_USERNAME,
			MEMSUB_PASSWORD,
			MEMSUB_LAST_LOGIN_DATE,
			MEMSUB_ACCOUNT_BALANCE
		) VALUES (
			@member_code,
			@subTypeCode,
			CURDATE(),
			CURDATE() + INTERVAL 12 MONTH,
			@status,
			@username,
			@password,
			NULL,
			0
		);

	INSERT INTO MEMBER_CALLSIGN (
			MEMBER_CODE,
			MEMBER_CALLSIGN
		) VALUES (
			@member_code,
			@callsign
		);
		
	INSERT INTO MEMBER_CLUB (
			MEMBER_CODE,
			CLUB_CODE,
			MEMCLUB_JOIN_DATE
		) VALUES (
			@member_code,
			@club_code,
			CURDATE()
		);
		
	INSERT INTO CONTACT_DETAILS (
			CONTACT_CODE,
			CONTACT_PRIMARY_PHONE,
			CONTACT_SECONDARY_PHONE,
			CONTACT_CELLPHONE,
			CONTACT_FAX,
			CONTACT_EMAIL
		) VALUES (
			@contact_code,
			@primary_phone,
			@secondary_phone,
			@cellphone,
			@fax,
			@email
		);

	SET @contact_code = LAST_INSERT_ID();

	INSERT INTO ADDRESS (
			ADDRESS_CODE,
			ADDRESS_APARTMENT_#,
			ADDRESS_COMPLEX_NAME,
			ADDRESS_STREET_#,
			ADDRESS_STREET_NAME,
			ADDRESS_SUBURB,
			ADDRESS_CITY,
			ADDRESS_PROVINCE,
			ADDRESS_POSTAL_CODE,
			ADDRESS_COUNTRY,
			ADDRESS_TYPE
		) VALUES (
			@address_code,
			@apartment_#,
			@complex_name,
			@street_#,
			@street_name,
			@suburb,
			@city,
			@province,
			@postal_code,
			@country,
			@address_type
		);

	SET @address_code = LAST_INSERT_ID();

	UPDATE MEMBER SET CONTACT_CODE = @contact_code, ADDRESS_CODE = @address_code WHERE MEMBER_CODE = @member_code;

COMMIT;